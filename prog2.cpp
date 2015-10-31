#pragma once
#include "stdafx.h"
// демонстрация композиции: объект с объектами-членами
#include <iostream>
 
#include "date.h"
using namespace std;
 
int main()
{
	  int dayy,
      monthh,
      yearr,
      z;
 
  Date d(3, 12, 1988);
  cout<<'\n';
 
  // Формат 05.01.1997
  d.print();
 
 // cout<<'\n';
 
  // Формат 5 января 1997 года.
  d.print_Day_StringMonth_Year();
     
  cout<<endl;
  const size_t N=3;
  Date a[N]= {Date(1,2,1999),Date(12,12,1999), Date(3,11,1994)};
  do{
    cout<<"\n Enter '0' START AND '-1' FINISH: ";
    cin>>z;
 
    cout<<endl;
 
      cout<<"Enter Day: ";
      cin>>dayy;
      cout<<"Enter Month: ";
      cin>>monthh;
      cout<<"Enter Year: ";
      cin>>yearr;
 
      // Функция установки и проверки правильности ввода
      d.setDate(dayy, monthh, yearr);
 
      // Вывод вариантов отображения
      d.print();
      d.print_Day_StringMonth_Year();
      }
  while(z != -1);
 
  cin>>z;

        return 0;
}
