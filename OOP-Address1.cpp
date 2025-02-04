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
    Address() {}

    void getOutputAdderss(std::ofstream& foul) const
    {

        foul << Cities << " " << Streets << " " << NumberHouse << " " << NumberApartment << std::endl;

    }

};

int main()
{

    setlocale(LC_ALL, "Ru");

    int CountAddress;
    std::ifstream fil("in.txt");
    std::ofstream foul("out1.txt");
    if (!foul.is_open())
    {
        std::cout << " Не получилось открыть файл out.txt" << std::endl;
        return 1;
    }

    if (!fil.is_open())
    {
        std::cout << "Не получилось открыть файл in.txt" << std::endl;
        return 1;
    }
    fil >> CountAddress;
    foul << CountAddress << std::endl;
    Address* array = new Address[CountAddress];

    for (int i = 0; i < CountAddress; ++i)
    {
        std::string city;
        std::string street;
        int HouseNumber;
        int ApartmentNumbre;
        fil >> city >> street >> HouseNumber >> ApartmentNumbre;
        array[i] = Address(city, street, HouseNumber, ApartmentNumbre);

    }
    std::reverse(array, array + CountAddress);
    for (int i = 0; i < CountAddress; ++i)
    {
        array[i].getOutputAdderss(foul);
    }



    delete[] array;
    fil.close();
    foul.close();

}