
#include <stdio.h>
#include <dstring.h>
#include <iostream>
#include <fstream>
#include <sysmac.h>
#include <System.hpp>

class ImpFromTxt
{
	AnsiString S1; //переменная для выбранного текста из файла
	AnsiString buf; //буферная переменная для записи необходимых слов


	public:

	AnsiString Import(const char* Aftr, int Chislo=0, ...)
	{                                               //^число слов после которых необходимо вычленить слова
//	using namespace std;
			
			size_t count=0; //Число символов в файле
			char S; //для подсчета символов
			const char* word_before = "Точка: "; //слово, после которого необходимо выделить слово
			/*Просто считаем число символов*/
			ifstream f(Aftr);
			while (!f.eof())
			{
				f.get(S);
				count++;
			}
			f.close();

			/*Добавляем текст в переменную*/

			char *S2=new char [count]; //Выделяем память по определенному числу символов
			for (int i=0;i<count;i++) S2[i]=NULL; //Очищаем строку от хлама
				ifstream f2(Aftr);  //создаем поток для работы с файлом
				 int i=0; //куроср на текущий символ (как номер буквы в слове)

				 while (!f2.eof()) //Проходим ао файлу
				 {
					 f2.get(S2[i]); //Записываем симыол за символом
					 i++; //передвинули курсор для записи следующего символа
				 }
         
				f2.close(); //закончили работу с файлом
				S1 = S2;
//				cout<<S2<<endl; //Теперь переменная char[] содержит текст из файла

		  	delete []S2; //освобождаем память
			/**************************************/
			switch (Chislo)  //цикл для выбора количества видов слов
			{                //слова будут собираться в буферной переменной
							 //для возвращения в основную программу

                case 2:
						break;
				case 1:	{   // TX;
							 while (S1.Pos(word_before))
							  {
									char buf1[100]= " ";
									int j=0;
									i=(S1.Pos(word_before)) ? (S1.Pos(word_before)+strlen(word_before)) : 0;
									int M = S1.Pos(word_before); //индекс первой буквы Т в первом нахождении слова Точка
									int L = S1.Length(); //длинна всего текста

									if (i)
									while (S1[i] != '\n')
									{
										buf1[j]=S1[i];
										j++;
										i++;
									}
									buf1[strlen(buf1)] = '\r';
									buf1[strlen(buf1)] = '\n';
									buf += buf1;
								   //buf = buf.Insert((S1.SubString(S1.Pos("Точка:")+8,5)),(S1.Pos("Точка:")+8));
									S1 = S1.SubString(S1.Pos(word_before)+strlen(buf1)-1+strlen(word_before),S1.Length()-(S1.Pos(word_before)+strlen(word_before)+strlen(buf1)-2));
								   //-1 и -2 в этом присваивании поставлены для компенсации добавленных лишних символов \r \n
									L = S1.Length();
							  }
						}
						break;


				

				case 3:
						break;


				default:
                ;
			}

			return buf;
	}
};
