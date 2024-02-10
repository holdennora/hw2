#ifndef MY_DATASTORE_H
#define MY_DATASTORE_H

#include "datastore.h"
#include <vector>
#include <set>
#include <map>
#include <string>
#include "product.h"
#include "user.h"

class MyDataStore : public DataStore
{
  public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p) override;
    void addUser(User* u ) override;
    void dump(std::ostream& ofile) override;


    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void addToCart(std::string& username, size_t hit_result_index);
    void viewCart(const std::string& username) ;
    void saveDatabase(const std::string& database) ;
    void buyCart(const std::string& username);

  private:
    std::vector<Product*> products_;
    std::vector<User*> users_;
    std::vector<Product*> searchResults_;

    std::map<std::string, std::set<Product*>> keywordIndex;
    std::map<std::string, std::vector<Product*>> cartIndex;


};

#endif