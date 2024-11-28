#include <iostream>
#include <string>
#include <stdexcept>
#include <windows.h>
using namespace std;

// Модель: отвечает за бизнес-логику
class Model {
public:
    int add(int number1, int number2) {
        return number1 + number2;
    }
};

// Представление: отображает данные и запрашивает ввод
class View {
public:
    void displayResult(const string& result) {
        cout << result << endl;
    }

    void displayInputPrompt() {
        cout << "Введите два числа для сложения:" << endl;
    }

    void getUserInput(int& number1, int& number2) {
        cout << "Введите первое число: ";
        cin >> number1;
        cout << "Введите второе число: ";
        cin >> number2;
    }
};

// Контроллер: управляет взаимодействием между моделью и представлением
class Controller {
public:
    Controller(Model& model, View& view) : model(model), view(view) {}

    void run() {
        view.displayInputPrompt();

        int number1, number2;
        view.getUserInput(number1, number2);

        try {
            int result = model.add(number1, number2);
            view.displayResult("Результат: " + to_string(result));
        }
        catch (const exception& e) {
            view.displayResult("Ошибка: " + string(e.what()));
        }
    }

private:
    Model& model;
    View& view;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Model model;
    View view;
    Controller controller(model, view);

    controller.run();

    return 0;
}
