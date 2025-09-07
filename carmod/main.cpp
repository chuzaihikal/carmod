#include <iostream>
using namespace std;


class Car {
    char* model = nullptr;
    char* country = nullptr;
    char* color = nullptr;
    int year = 0;
    double price = 0.0;

public:
    char* getModel() const { return model; }
    char* getCountry() const { return country; }
    char* getColor() const { return color; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    void SetModel(const char* model) {
        delete[] this->model;
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }
    void SetCountry(const char* country) {
        delete[] this->country;
        this->country = new char[strlen(country) + 1];
        strcpy(this->country, country);
    }
    void SetColor(const char* color) {
        delete[] this->color;
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
    }
    void SetYear(const int year) {
        if (year <= 0) {
            cout << "invalid year\n";
            return;
        }
        this->year = year;
    }
    void SetPrice(const double price) {
        if (price <= 0) {
            cout << "invalid price\n";
            return;
        }
        this->price = price;
    }
    Car() {
        SetModel("no model");
        SetCountry("no country");
        SetColor("no color");
        this->year = 0;
        this->price = 0;
    }
    Car(const char* model, const char* country, const char* color, int year, double price) {
        if (model == nullptr | country == nullptr | color == nullptr) {
            cout << "Error, null input (parameters set to default)\n";
            SetModel("No model");
            SetCountry("No country");
            SetColor("No color");
            return;
       }
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
        this->country = new char[strlen(country) + 1];
        strcpy(this->country, country);
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
        this->year = year;
        this->price = price;
    }
    void Print() {
        cout << "| Model: " << model << " | " << country << " | " << color << " | " << year << " | " << price << "$ |\n";
    }
    void ChangeProperties() {
        const int BufferSize = 256;
        char NewModel[BufferSize];
        char NewCountry[BufferSize];
        char NewColor[BufferSize];
        int NewYear = 0;
        double NewPrice = 0;

        cout << "\nEnter new model > ";
        cin.getline(NewModel, BufferSize);

        cout << "Enter new country > ";
        cin.getline(NewCountry, BufferSize);

        cout << "Enter new color > ";
        cin.getline(NewColor, BufferSize);

        cout << "Enter new year > "; cin >> NewYear;
        cin.ignore();
        SetYear(NewYear);

        cout << "Enter new price > "; cin >> NewPrice;
        cin.ignore();
        SetPrice(NewPrice);

        SetModel(NewModel);
        SetCountry(NewCountry);
        SetColor(NewColor);
    }
    ~Car() {
        delete[] model;
        delete[] country;
        delete[] color;
        model = nullptr;
        country = nullptr;
        color = nullptr;
    }
};
int main() {
    Car car_1{ "Dodge Challenger SRT Demon", "USA", "Black", 2019, 150000 };
    car_1.Print();
    car_1.ChangeProperties();
    car_1.Print();

    return 0;
}
//ne rabotaet strcpy pochemuto(