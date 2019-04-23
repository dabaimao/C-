#ifndef SALES_DATA_H
#define SALES_DARA_H
#include <string>
struct Sales_data
{
	Sales_data() = default;
	Sales_data(const std::string & s) :bookNo(s) {}
	Sales_data(const std::string & s,unsigned n, double p) :
							bookNo(s) ,units_sold(n),revenues(p){}


	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	std::string  bookNo;
	unsigned units_sold = 0;
	double revenues = 0.0;


};
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenues += rhs.revenues;
	return *this;
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenues / units_sold;
}

#endif 
