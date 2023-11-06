// Lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

class GeometricFigure {
protected:
    double centerX;
    double centerY;
    double rotationAngle;
    double scale;

public:
    GeometricFigure(double x, double y, double angle, double scale)
        : centerX(x), centerY(y), rotationAngle(angle), scale(scale) {}

    virtual void showOnScreen() = 0;
    virtual void makeInvisible() = 0;
    virtual void rotate(double angle) = 0;
    virtual void move(double dx, double dy) = 0;
};

class Rectangle : public GeometricFigure {
private:
    double width;
    double height;

public:
    Rectangle(double x, double y, double angle, double scale, double w, double h)
        : GeometricFigure(x, y, angle, scale), width(w), height(h) {}

    void showOnScreen() override {
        // Ваш код для відображення прямокутника на екрані
        std::cout << "Displaying Rectangle at (" << centerX << ", " << centerY << "), Width: " << width << ", Height: " << height << std::endl;
    }

    void makeInvisible() override {
        // Ваш код для зроблення прямокутника невидимим
        std::cout << "Making Rectangle invisible" << std::endl;
    }

    void rotate(double angle) override {
        // Ваш код для обертання прямокутника
        rotationAngle += angle;
        std::cout << "Rotating Rectangle by " << angle << " degrees" << std::endl;
    }

    void move(double dx, double dy) override {
        // Ваш код для переміщення прямокутника на вказаний вектор
        centerX += dx;
        centerY += dy;
        std::cout << "Moving Rectangle by (" << dx << ", " << dy << ")" << std::endl;
    }
};

class Triangle : public GeometricFigure {
private:
    double sideLength;

public:
    Triangle(double x, double y, double angle, double scale, double side)
        : GeometricFigure(x, y, angle, scale), sideLength(side) {}

    void showOnScreen() override {
        // Ваш код для відображення трикутника на екрані
        std::cout << "Displaying Triangle at (" << centerX << ", " << centerY << "), Side Length: " << sideLength << std::endl;
    }

    void makeInvisible() override {
        // Ваш код для зроблення трикутника невидимим
        std::cout << "Making Triangle invisible" << std::endl;
    }

    void rotate(double angle) override {
        // Ваш код для обертання трикутника
        rotationAngle += angle;
        std::cout << "Rotating Triangle by " << angle << " degrees" << std::endl;
    }

    void move(double dx, double dy) override {
        // Ваш код для переміщення трикутника на вказаний вектор
        centerX += dx;
        centerY += dy;
        std::cout << "Moving Triangle by (" << dx << ", " << dy << ")" << std::endl;
    }
};

int main() {
    double x, y, angle, scale;
    std::cout << "Enter center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter rotation angle (in degrees): ";
    std::cin >> angle;
    std::cout << "Enter scale factor: ";
    std::cin >> scale;

    GeometricFigure* figure;

    int choice;
    std::cout << "Choose a figure type (1 for Rectangle, 2 for Triangle): ";
    std::cin >> choice;

    if (choice == 1) {
        double width, height;
        std::cout << "Enter rectangle width and height: ";
        std::cin >> width >> height;
        figure = new Rectangle(x, y, angle, scale, width, height);
    }
    else if (choice == 2) {
        double sideLength;
        std::cout << "Enter side length of the triangle: ";
        std::cin >> sideLength;
        figure = new Triangle(x, y, angle, scale, sideLength);
    }
    else {
        std::cerr << "Invalid choice. Exiting." << std::endl;
        return 1;
    }

    figure->showOnScreen();
    figure->rotate(45);  // Rotate by 45 degrees
    figure->move(2, 3);  // Move by (2, 3)
    figure->makeInvisible();

    delete figure;  // Release memory

    return 0;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
