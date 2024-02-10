#include "clothing.h"
#include "util.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Clothing::Clothing( const std::string& category,const std::string& name, double price, int quantity,
          const std::string& size, const std::string& brand )
    : Product(category, name, price, quantity), size_(size), brand_(brand){}
Clothing::~Clothing(){}
    std::set<std::string> Clothing::keywords() const
    {
      std::set<std::string> clothingKeywords;
      std::set<std::string> brandAdjust = parseStringToWords(brand_);
      std::set<std::string> nameAdjust = parseStringToWords(name_);
      clothingKeywords.insert(nameAdjust.begin(), nameAdjust.end());
      clothingKeywords.insert(brandAdjust.begin(), brandAdjust.end());

      return clothingKeywords;
    }
    std::string Clothing::displayString() const
    {
      std::ostringstream oss;
      oss << name_ << std::endl;
      oss << "Size: " << size_ << " "
      << "Brand: " << brand_ << std::endl;
      oss << std::fixed << std::setprecision(2) << price_ << " " 
      << qty_ << " left." << std::endl;
      return oss.str();
    }
    void Clothing::dump(std::ostream& os) const
    {
      os << "clothing" << '\n'
        << getName() << '\n'
        << getPrice() << '\n'
        << getQty() << '\n'
        << size_ << '\n'
        << brand_ << '\n';
    }