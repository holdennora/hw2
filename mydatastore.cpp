#include "mydatastore.h"
#include <iostream>
#include "util.h"
#include "product.h"

MyDataStore::MyDataStore()
{
}

MyDataStore::~MyDataStore()
{
   for (size_t i = 0; i < products_.size(); i++)
  {
    delete products_[i];
  }
  products_.clear();
   for (size_t j = 0; j < users_.size(); j++)
  {
    delete users_[j];
  }
  users_.clear();
}

void MyDataStore::addProduct(Product* p)
{
  products_.push_back(p);
  std::set<std::string> keywords = p->keywords();
  // iterates through keywords to find match of inserted product
  for(std::set<std::string>::const_iterator it = keywords.begin(); it != keywords.end(); ++it)
  {
    std::string key = *it;
    key = convToLower(key);
    keywordIndex[key].insert(p);
  }
}

void MyDataStore::addUser(User* u)
{
  if(u != nullptr)
  {
    users_.push_back(u);
  }
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
  std::set<Product*> results;
  //Seperates into AND/OR searching 
  if (type == 0 )
  { 
    for(std::vector<std::string>:: iterator it = terms.begin(); it != terms.end(); ++it)
    {
      std::set<Product*>& tresults = keywordIndex[*it];
      if(it == terms.begin())
      {
        // Ulilizes from util.h
        results = setUnion(results, tresults);
      }
      else
      {
        // Ulilizes from util.h
        results = setIntersection(results, tresults);
      }
    }
  }
  else 
  {
    for(std::vector<std::string>:: iterator it = terms.begin(); it != terms.end(); ++it)
    {
      std::set<Product*>& tresults = keywordIndex[*it];
      // Ulilizes from util.h
      results = setUnion(results, tresults);
    }
  }


  searchResults_.assign(results.begin(), results.end());



  return searchResults_;
}

void MyDataStore::buyCart(const std::string& username)
{
  // outer loops through users
  for (size_t i = 0; i < users_.size(); i++)
  {
    std::string currName = convToLower(users_[i]->getName());
    if(currName == convToLower(username))
    {
      std::vector<Product*>& cart = cartIndex[convToLower(username)];
      // inner loops through cart 
      for (size_t j = 0; j < cart.size(); j++)
      {
        Product* tempProd = cart[j];
        // checks if purchasable
        if(tempProd->getQty() > 0 && users_[i]->getBalance() >= tempProd->getPrice())
        {
          tempProd->subtractQty(1);
          users_[i]->deductAmount(tempProd->getPrice());
          std::cout << "Product Purchased: " << tempProd->getName() << std::endl;
          cart.erase(cart.begin()+j);
          j--;
        }
      }
      break;
    }
    // checks if username was not valid
  if (i == users_.size()-1)
  {
    std::cout << "Invalid username" << std::endl;
  }
  }
}




void MyDataStore::viewCart(const std:: string& username)
{
  User* user = nullptr;

  bool userExists = false ;
// inner loops through users 
  for (size_t i = 0; i < users_.size(); i++)
  {
    User* u = users_[i];
    // compares 
    if (convToLower(u->getName()) == convToLower(username))
    {
      user = u;
      userExists = true;
      break;
    }
  }
  if (!userExists)
  {
    std::cout << "Invalid username" << std::endl;
    return;
  }

  std::vector<Product*>& cart = cartIndex[convToLower(username)];
  if(cart.empty())
  {
    std::cout << "Cart is empty" << std::endl;
    return;
  }
  for(size_t i = 0; i < cart.size(); i++)
  {
    Product* currProd = cart[i];
    std::cout << "Item " << i+1 << std::endl;
    std::cout << currProd->displayString() << std::endl;
  }
}

void MyDataStore::dump(std::ostream& ofile)
{
  ofile << "<products>" << std::endl;
  for (Product* product: products_)
  {
    product->dump(ofile);
  }
  ofile << "</products>" << std::endl;

  ofile << "<users>" << std::endl;
  for (User* user: users_)
  {
    user->dump(ofile);
  }
  ofile << "</users>" << std::endl;
}

void MyDataStore::addToCart(std::string& username, size_t hit_result_index)
{
  int found = 0;
  // checks valid hit index
  if(hit_result_index <= 0 || hit_result_index > searchResults_.size() )
  {
    std::cout << "Invlaid request" << std::endl;
    return;
  }
  // loops through users 
  for (size_t j = 0; j < users_.size(); j++)
  {
    if(convToLower(users_[j]->getName()) == convToLower(username))
    {
      found = 1;
      break;
    }
  }
  if(found == 0)
  {
    std::cout << "Invalid request" << std::endl;
    return;
  }
  else 
  {
    // only runs if valid request
    Product* selectedProduct = searchResults_[hit_result_index-1];
    cartIndex[convToLower(username)].push_back(selectedProduct);
  }

}