#include <iostream>
#include <string>

using namespace std;

class number_sys
{
private:
    string integer;
    string fractional;
    int radix;
public:
    number_sys(string num, int radix_)
    {
        this -> radix = radix_;
        string str;
        this -> integer = num.substr(0, num.find_first_of('.'));
        this -> fractional = num.substr(num.find_first_of('.')+1, num.size() - num.find_first_of('.'));
    }
    number_sys convert_to_radix(double number, int radix, int precision = 10);
    friend ostream & operator << (ostream &cout_bn, const number_sys &num);
    friend istream & operator >> (istream &cin_bn, number_sys &num);
    number_sys() {};
    void set_radix(int radix_);
    void set_integer(string integer_);
    void set_fractional(string fractional_);
    int get_radix();
    string get_integer();
    string get_fractional();
    void outup();

};

ostream & operator << (ostream &cout_bn, const number_sys &num)
{
    cout_bn << num.integer << "." << num.fractional<< "_" << num.radix << endl;
    return cout_bn;
}

istream & operator >> (istream &cin_bn, number_sys &num)
{
    string str;
    int rad;
    cin_bn >> str;
    cin_bn >> rad;
    num = number_sys(str, rad);
}
void number_sys::set_radix(int radix_)
{
    this->radix = radix_;
}

void number_sys::set_integer(string integer_)
{
    this->integer = integer_;
}

void number_sys::set_fractional(string fractional_)
{
    this->fractional = fractional_;
}

int number_sys::get_radix()
{
    return this -> radix;
}

string number_sys::get_integer()
{
    return this -> integer;
}

string number_sys::get_fractional()
{
    return this -> fractional;
}

number_sys convert_to_radix(double number, int radix, double error)
{
    ///transfering integer part
    int integer = int(number);
    int max_ = 1;
    while(max_<=integer)
    {
        max_*=radix;
    }
    max_/=radix;
    string str = "";
    while(max_>0)
    {
        int tmp = integer/max_;
        integer%=max_;
        max_/=radix;
        if(tmp <10)
        {
            char a = '0' + tmp;
            str = str + a;
        }
        else
        {
            char a = 'A' + tmp - 10;
            str = str + a;
        }
    }
    ///define answer
    number_sys ans;
    ans.set_integer(str);
    ans.set_radix(radix);
    ///transfering fractional part
    str = "";
    double order = 1./radix;
    double float_ = number - int(number);
    double float_2 = number - int(number);
    while(error <= float_)
    {
        int tmp = int(float_/order);
        float_ -= tmp*order;
        order = order/radix;
        if(tmp <10)
        {
            char a = '0' + tmp;
            str = str + a;
        }
        else
        {
            char a = 'A' + tmp - 10;
            str = str + a;
        }
        if(float_ == 0)
        {
            break;
        }
    }
    /*while(int(float_/order) == 0)
    {
        str+="0";
        order = order/radix;
    }*///adding zeros to fractional parts
    ///completing answer
    ans.set_fractional(str);
    return ans;
}

void outup()
{
    cout<<"I THE INITIAL DATA"<<endl;
    cout<<" The initial decimal number: x_10 = ";
    double number;
    cin>>number;
    cout<<"The radix of the target numeral system: r = ";
    int rad;
    cin>>rad;
    cout<<"The required precission of the converted number: epsilon_sup = ";
    double er;
    cin>>er;
    number_sys a = convert_to_radix(number, rad, er);
    cout<<"II THE REZULTS OF THE CONVERSION"<<'\n';
    cout<<" The required number of the significant numerals s = "<<a.get_fractional().size()<<" that corresponds the given prcission epsilon_sup = "<<er<<'\n';
    cout<<" The result of the conversion: x_"<<rad<<" = "<<a<<'\n';
}

int main()
{
    outup();
}
