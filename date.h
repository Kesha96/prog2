#pragma once
class Date{
private:
	int dn_, mn_, yr_;
public:
	Date(int dn, int mn, int yr)
	{
        setDate(dn, mn, yr); // Функция правильной установки дня, месяца, и года
		dn_ = dn;
		mn_ = mn;
		yr_ = yr;
	}
    // печать  05.01.1997
    void print() const;
 
    // печать дат в формате 5 января 1997 год.
    void print_Day_StringMonth_Year() const;
    ~Date();
 
    // функцияи 'set' Установка и проверка вводимых параметров
    void setDate(int, int, int);   // установка дня, месяца, года
private:
    int day;       
    int month;     
    int year;     
 
    // функция для проверки соответствия дня месяца и году
    int checkDay(int); 
 };
 
