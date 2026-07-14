#include "calculator.h"

bool ReadNumber(Number &result)
{

    if (!(std::cin >> result))
    {
        return false;
    }

    return true;
}

bool ReadCommand(std::string &command)
{

    if (!(std::cin >> command))
    {
        return false;
    }

    // Если это комманда **, то сразу переделываем под удобную для моего кода комманду.
    if (command == "**")
    {
        command = "^";
        return true;
    }

    if (command.size() > 1)
    {
        return false;
    }

    return true;
}

bool CommandInitialization(Number &first_number, Number &second_number, Number &buffer, std::string &command, bool &buffer_checker)
{
    char symbol_of_command = command[0];
    static const std::string simple_arithmetic = "+-/*^:";

    if (simple_arithmetic.find(symbol_of_command) != simple_arithmetic.npos)
    {
        if (!ReadNumber(second_number))
        {
            throw std::runtime_error("Error: Numeric operand expected");
        }
    }

    switch (symbol_of_command)
    {

    case '+':
        first_number += second_number;
        second_number = 0;
        break;

    case '-':
        first_number -= second_number;
        second_number = 0;
        break;

    case '/':
        first_number /= second_number;
        second_number = 0;
        break;

    case '*':
        first_number *= second_number;
        second_number = 0;
        break;

    // Он же **
    case '^':
        first_number = std::pow(first_number, second_number);
        second_number = 0;
        break;

    case ':':
        first_number = second_number;
        break;

    case '=':
        std::cout << first_number << std::endl;
        break;

    case 'q':
        return true;

    case 's':
        buffer = first_number;
        buffer_checker = true;
        break;

    case 'l':
        if (!buffer_checker)
        {
            throw std::runtime_error("Error: Memory is empty");
        }
        first_number = buffer;
        break;

    case 'c':
        first_number = 0;
        break;

    default:
        throw std::runtime_error(std::string("Error: Unknown token ") + symbol_of_command);
    }

    // Продолжаем цикл.
    return false;
}

bool RunCalculatorCycle()
{
    Number buffer(0);
    bool buffer_checker = false;
    std::string command;

    Number first_number(0);
    Number second_number(0);

    if (!ReadNumber(first_number))
    {
        throw std::runtime_error("Error: Numeric operand expected");
    }

    while (true)
    {

        if (!ReadCommand(command))
        {
            throw std::runtime_error(std::string("Error: Unknown token ") + command);
        }

        if (CommandInitialization(first_number, second_number, buffer, command, buffer_checker))
        {
            return true;
        }
    }

    return true;
}