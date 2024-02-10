#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "product.h"

class Book: public Product{
  public:
    Book( const std::string& category, const std::string& name, double price, int quantity,
          const std::string& isbn, const std::string& author );
    virtual ~Book();
    
    virtual std::set<std::string> keywords() const override;
    virtual std::string displayString() const override;
    virtual void dump(std::ostream& os) const override;

  private:
    std::string isbn_;
    std::string author_;

};
#endif