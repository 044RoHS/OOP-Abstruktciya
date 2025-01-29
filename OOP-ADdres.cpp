#include <iostream>
#include <fstream>



class Address1
{
private:
    std::string Cities;
    std::string Streets;
    int NumberHouse;
    int NumberApartment;

public:
    Address1(std::string Citis, std::string Street, int House, int Apartment)
    {
        Cities = Citis;
        Streets = Street;
        NumberHouse = House;
        NumberApartment = Apartment;


    }
    Address1() {}

    void getOutputAdderss(std::ofstream& foul) const
    {

        foul << Cities << " " << Streets << " " << NumberHouse << " " << NumberApartment << std::endl;

    }

    
    void SortAddress1(Address1* adres, int sizearray)
    {
        for (int i = 0; i < sizearray; ++i)
        {
            for (int j = 0; j < sizearray - 1; ++j)
            {
                if (adres[j].Cities > adres[j + 1].Cities)
                {
                    std::swap(adres[j], adres[j + 1]);
                }
            }
        }

    }

};



int main()
{

    setlocale(LC_ALL, "Ru");

    int CountAddress;
    std::ifstream fil("in1.txt");
    std::ofstream foul1("out2.txt");
    if (!foul1.is_open())
    {
        std::cout << " Не получилось открыть файл out2.txt" << std::endl;
    }

    if (!fil.is_open())
    {
        std::cout << "Не получилось открыть файл in1.txt" << std::endl;

    }
    fil >> CountAddress;
    foul1 << CountAddress << std::endl;
    Address1* array = new Address1[CountAddress];

    for (int i = 0; i < CountAddress; ++i)
    {
        std::string city;
        std::string street;
        int HouseNumber;
        int ApartmentNumbre;
        fil >> city >> street >> HouseNumber >> ApartmentNumbre;
        Address1 adress(city, street, HouseNumber, ApartmentNumbre);
        array[i] = Address1(city, street, HouseNumber, ApartmentNumbre);

    }
    Address1 ads;
    ads.SortAddress1(array, CountAddress);
    for (int i = 0; i < CountAddress; ++i)
    {
        array[i].getOutputAdderss(foul1);
    }


    delete[] array;
    fil.close();
   
}