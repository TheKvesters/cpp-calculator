#pragma once
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
