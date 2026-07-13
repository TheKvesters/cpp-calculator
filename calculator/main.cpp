#include <iostream>
#include <string>
#include <cmath>

using Number = double;

// Возвращает true, если удалось прочитать число
// и сохранить его в Number.
bool ReadNumber(Number& result);

bool ReadCommand(std::string& oper);

// Возвращает true, если работа завершилась штатно 
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle(); 

bool ReadNumber(Number& result){

    if(!(std::cin >> result)){
        return false;
    }

    return true;
}

bool ReadCommand(std::string& command){

    if(!(std::cin >> command)){
        return false;
    }

    if(command == "**"){ //Если это комманда **, то сразу переделываем под удобную для моего кода комманду.
        command = "^";
        return true;
    } 
    
    if(command.size() > 1){
        return false;
    }

    return true;
}

bool CommandInitialization(Number& first_number, Number& second_number, Number& buffer, std::string& command, bool& buffer_checker){
    char symbol_of_command = command[0];
    std::string simple_arifmetic = "+-/*^:";

    if(simple_arifmetic.find(symbol_of_command) != simple_arifmetic.npos){
        if(!ReadNumber(second_number)){
            throw "Error: Numeric operand expected";
        }
    }

    switch(symbol_of_command){

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

        case '^': //Он же **

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

        if(!buffer_checker){
            throw "Error: Memory is empty";
        }
        first_number = buffer;
        break;

        case 'c':

        first_number = 0;
        break;
        
        default:

        throw "Error: Unknown token " + symbol_of_command;
    }

    return false; //Тем самым продолжаем цикл.
}


bool RunCalculatorCycle(){
    Number buffer(0);
    bool buffer_checker = false;
    std::string command;

    Number first_number(0);
    Number second_number(0);

    if(!ReadNumber(first_number)){
        throw "Error: Numeric operand expected";
    }

    while(true){

        if(!ReadCommand(command)){
            throw "Error: Unknown token " + command;
        }

        if(CommandInitialization(first_number, second_number, buffer, command, buffer_checker)){
            return true;
        }

    }

    return true;
}

int main(){
	bool cycle_succes = false;
	try{
		cycle_succes = RunCalculatorCycle();
	} catch(const std::string& error) {
		std::cerr << error;
	}
	return cycle_succes ? 0 : 1;
}
