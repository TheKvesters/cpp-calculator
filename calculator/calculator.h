#include "calculator.h"

bool ReadNumber(Number& result){

    if(!(std::cin >> result)){
        return false;
    }

    return true;
}

bool ReadCommand(std::string& command){

    std::cin >> command;

    if(command == "**"){ //Если это комманда **, то сразу переделываем под удобную для моего кода комманду.
        command = "^";
        return true;
    } else if(command.size() > 1){
        return false;
    }

    return true;
}

bool CommandInitialization(Number& first_num, Number& second_num, Number& buffer, std::string& command, bool& buffer_checker){
    char symbol_of_command = command[0];

    switch(symbol_of_command){
        case '+':
        if(!ReadNumber(second_num)){
            std::cerr << "Error: Numeric operand expected";
            return false;
        }
        first_num += second_num;
        second_num = 0;
        break;

        case '-':
        if(!ReadNumber(second_num)){
            std::cerr << "Error: Numeric operand expected";
            return false;
        }
        first_num -= second_num;
        second_num = 0;
        break;

        case '/':
        if(!ReadNumber(second_num)){
            std::cerr << "Error: Numeric operand expected";
            return false;
        }
        first_num /= second_num;
        second_num = 0;
        break;

        case '*':
        if(!ReadNumber(second_num)){
            std::cerr << "Error: Numeric operand expected";
            return false;
        }
        first_num *= second_num;
        second_num = 0;
        break;

        case '^': //Он же **
        if(!ReadNumber(second_num)){
            std::cerr << "Error: Numeric operand expected";
            return false;
        }
        first_num = std::pow(first_num, second_num);
        second_num = 0;
        break;

        case ':':
        if(!ReadNumber(second_num)){
            std::cerr << "Error: Numeric operand expected";
            return false;
        }
        first_num = second_num;
        break;

        case '=':
        std::cout << first_num << std::endl;
        break;

        case 'q':
        return false;       

        case 's':
        buffer = first_num;
        buffer_checker = true;
        break;

        case 'l':
        if(!buffer_checker){
            std::cerr << "Error: Memory is empty" << std::endl;
            return false;
        }
        first_num = buffer;
        break;

        case 'c':
        first_num = 0;
        break;
        
        default:
        std::cerr << "Error: Unknown token " << symbol_of_command <<std::endl;
        break;
    }

    return true;
}


bool RunCalculatorCycle(){
    Number buffer(0);
    bool buffer_checker = false;
    std::string command;

    Number first_num(0), second_num(0);

    if(!ReadNumber(first_num)){
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }

    while(true){

        if(!ReadCommand(command)){
            std::cerr << "Error: Unknown token " << command << std::endl;
            return false;
        }

        if(!CommandInitialization(first_num, second_num, buffer, command, buffer_checker)){
            return false;
        }

    }

    return true;
}
