#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include "product.h"

class Movie: public Product{
  public:
    Movie( const std::string& category, const std::string& name, double price, int quantity,
          const std::string& genre, const std::string& rating);
    virtual ~Movie();

    virtual std::set<std::string> keywords() const override;
    virtual std::string displayString() const override;
    virtual void dump(std::ostream& os) const override;

  private:
    std::string genre_;
    std::string rating_;
};

#endif