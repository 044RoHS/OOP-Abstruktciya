#include <iostream>
#include <fstream>

class Address
{
private:
    std::string Cities;
    std::string Streets;
    int NumberHouse;
    int NumberApartment;
public:
    Address(std::string Citis, std::string Street, int House, int Apartment)
    {
        Cities = Citis;
        Streets = Street;
        NumberHouse = House;
        NumberApartment = Apartment;


    }
    std::string getOutputAdderss()
    {
       
    
    }
};



    int main()
    {

        setlocale(LC_ALL, "RU");
        std::string city;
        std::string street;
        int HouseNumber;
        int ApartmentNumbre;
        int CountAddress;
  
       
        std::ifstream fil("in.txt");
        std::ofstream fout("out.txt");
        int* array = new int{};
        if (!fout.is_open())
        {
            std::cout << "Не получилось открыть файл out.txt" << std::endl;

        }
        if (!fil.is_open())
        {
            std::cout << "Не получилось открыть файл in.txt" << std::endl;

        }
        fil >> CountAddress;
 
        for (int i = 0; i < CountAddress; i++)
        {
            fil >> city >> street >> HouseNumber >> ApartmentNumbre;
            Address Adres(city, street, HouseNumber, ApartmentNumbre);
        
            
        }

        delete[] array;



        fil.close();
        fout.close();





    }


