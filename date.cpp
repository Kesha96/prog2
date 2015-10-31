#include <iostream>
#include "date.h"
using namespace std;
 
// конструктор: поддержка соответствующего значения месяца;
//Date::Date(int dy, int mn, int yr)
//{
//  setDate(dy, mn, yr); // Функция правильной установки дня, месяца, и года
//}
// печать объекта Date в форме месяца/дня/года. 05.01.1997--------------------
void Date::print() const 
{
  int NumbNullDay_and_Month, // Счётчик
      NumbNull_Day, 
      NumbNull_Month; 
 
  static const char *NumberDay_Month [10] = {" ", "01", "02", "03", "04", "05", "06", "07", "08", "09"};
 
  // Проверка дня, если в числе ДНЯ один разряд, вычислить соответствующий индекс массива NumberDay_Month...
  if(day < 10){
     for(NumbNullDay_and_Month = 0; NumbNullDay_and_Month < 11; NumbNullDay_and_Month++){
        if(NumbNullDay_and_Month == day)
           NumbNull_Day = NumbNullDay_and_Month;
    }
  }
  // Если в числе ДНЯ, больше одного разряда, то присвоить переменной NumbNull_Day, тоже число, что и было
  else if(day > 9)
     NumbNull_Day = day;
 
  // Проверка дня, если в числе МЕСЯЦА один разряд, вычислить соответствующий индекс массива NumberDay_Month...
  if(month < 10){
     for(NumbNullDay_and_Month = 0; NumbNullDay_and_Month < 11; NumbNullDay_and_Month++){
        if(NumbNullDay_and_Month == month)
           NumbNull_Month = NumbNullDay_and_Month;
    }
  }
  // Если в числе МЕСЯЦА, больше одного разряда, то присвоить переменной NumbNull_Day, тоже число, что и было
  else if(month > 9)
     NumbNull_Month = month;
 
  // Вывод вариантов
  if(day < 10 && month < 10) // Если в ДНЕ И в МЕСЯЦЕ число меньше десяти
    cout<<NumberDay_Month[NumbNull_Day]<<"."<<NumberDay_Month[NumbNull_Month]<<"."<<year<<endl;
  else if(day < 10 && month > 9) // Если в ДНЕ меньше деСяти, И в МЕСЯЦЕ больше деВяти
    cout<<NumberDay_Month[NumbNull_Day]<<"."<<NumbNull_Month<<"."<<year<<endl;
  else if(day > 9 && month < 10) // Если в ДНЕ больше деВяти, И в МЕСЯЦЕ больше деСяти
    cout<<NumbNull_Day<<"."<<NumberDay_Month[NumbNull_Month]<<"."<<year<<endl;
  else if(day > 9 && month > 9)  // Если в ДНЕ И в МЕСЯЦЕ число больше деСяти
    cout<<NumbNull_Day<<"."<<NumbNull_Month<<"."<<year<<endl;
}

// печать дат в формате число, строка названия месяца, год--------------------
void Date::print_Day_StringMonth_Year() const
{
  int i;
  static const char *Month [13] = {"", "Yanvaria", "Fevralia", "Marta", "Aprelia",
                                  "May", "Yuni", "Yuli", "Avgusta", "Sentyabria",
                                  "Ortyabria", "Noyabria","Dekabria"};
 
      for(i = 0; i < 14; i++){
          if(month == i)
              cout<<day<<" "<<Month[i]<<" "<<year<<" God."<<endl;
        }
}

int Date::checkDay(int testDay)
{
  static const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
  if(testDay > 0 && testDay <= daysPerMonth[month])
     return testDay;
 
  if(month == 2 &&      // февраль: проверка високосноо года
           testDay == 29 &&
              (year % 400 == 0 || (year %4 == 0 && year % 100 != 0)))
     return testDay;
 
  cout<<"  DENY:  "<<testDay<<" NEPRAVILNIY. USTANOVITY DENY 1 \n\n";
 
  print();
  print_Day_StringMonth_Year();
 
  return 1;           // если значение неправильное
}
// Проверка и Установка даты через setDate------------------------------------
void Date::setDate(int dy, int mn, int yr)
{
  if(mn > 0 && mn <= 12)     // проверка месяца
     month = mn;
  else{
     month = 1;
     cout<<"  MEZYAC: "<<mn<<" NEPRAILNIY. USTANOVITY MEZYAC 1. \n\n";
    }
  year = yr;
  day = checkDay(dy);       // проверка дня
 
  print();
  print_Day_StringMonth_Year();
 
  cout<<"\n  KONSTRUKPOR OBEKTA 'DATE'\n";
  cout<<endl;
}
// деструктор-----------------------------------------------------------------
Date::~Date()
{
  cout<<"  DESTRUKTOR DATE-OBEKTA DLA DATY ";
  print();
  cout<<endl;
}
 
