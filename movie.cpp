#include "movie.h"
#include <iostream>
#include "util.h"
#include <iomanip>
#include <sstream>

Movie::Movie( const std::string& category, const std::string& name, double price, int quantity,
          const std::string& genre, const std::string& rating )
    : Product(category, name, price, quantity), genre_(genre), rating_(rating){}
Movie::~Movie(){}
    std::set<std::string> Movie::keywords() const
    {
      std::set<std::string> movieKeywords;
      std::set<std::string> nameAdjust = parseStringToWords(name_);
      movieKeywords.insert(nameAdjust.begin(), nameAdjust.end());
      movieKeywords.insert(genre_);

      return movieKeywords;
    }
    std::string Movie::displayString() const
    {
      std::ostringstream oss;
      oss << name_ << std::endl;
      oss << "Genre: " << genre_ << " "
      << "Rating: " << rating_ << std::endl;
      oss << std::fixed << std::setprecision(2) << price_ << " " 
      << qty_ << " left." << std::endl;
      return oss.str();
    }
    void Movie::dump(std::ostream& os) const
    {
      os << "movie" << '\n'
        << getName() << '\n'
        << getPrice() << '\n'
        << getQty() << '\n'
        << genre_ << '\n'
        << rating_ << '\n';

    }