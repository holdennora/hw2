#include "book.h"
#include "util.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Book::Book( const std::string& category, const std::string& name, double price, int quantity,
          const std::string& isbn, const std::string& author )
    : Product(category, name, price, quantity), isbn_(isbn), author_(author){}
Book::~Book(){}
    std::set<std::string> Book::keywords() const
    {
      std::set<std::string> bookKeywords;
      std::set<std::string> authorAdjust = parseStringToWords(author_);
      std::set<std::string> nameAdjust = parseStringToWords(name_);

      bookKeywords.insert(isbn_);
      bookKeywords.insert(authorAdjust.begin(),authorAdjust.end());
      bookKeywords.insert(nameAdjust.begin(),nameAdjust.end());
      
      return bookKeywords;
    }
    std::string Book::displayString() const
    {
      std::ostringstream oss;
      oss << name_ << std::endl;
      oss << "Author: " << author_ << " ISBN: " << isbn_ << std::endl;
      oss << std::fixed << std::setprecision(2) << price_ << " " 
      << qty_ << " left." << std::endl;
      return oss.str();
    }
    void Book::dump(std::ostream& os) const
    {
      os << "book" << '\n'
        << getName() << '\n'
        << getPrice() << '\n'
        << getQty() << '\n'
        << isbn_ << '\n'
        << author_ << '\n';
    }