
#include <stdio.h>
#include <dstring.h>
#include <iostream>
#include <fstream>
#include <sysmac.h>
#include <System.hpp>

class ImpFromTxt
{
	AnsiString S1; //���������� ��� ���������� ������ �� �����
	AnsiString buf; //�������� ���������� ��� ������ ����������� ����


	public:

	AnsiString Import(const char* Aftr, int Chislo=0, ...)
	{                                               //^����� ���� ����� ������� ���������� ��������� �����
//	using namespace std;
			
			size_t count=0; //����� �������� � �����
			char S; //��� �������� ��������
			const char* word_before = "�����: "; //�����, ����� �������� ���������� �������� �����
			/*������ ������� ����� ��������*/
			ifstream f(Aftr);
			while (!f.eof())
			{
				f.get(S);
				count++;
			}
			f.close();

			/*��������� ����� � ����������*/

			char *S2=new char [count]; //�������� ������ �� ������������� ����� ��������
			for (int i=0;i<count;i++) S2[i]=NULL; //������� ������ �� �����
				ifstream f2(Aftr);  //������� ����� ��� ������ � ������
				 int i=0; //������ �� ������� ������ (��� ����� ����� � �����)

				 while (!f2.eof()) //�������� �� �����
				 {
					 f2.get(S2[i]); //���������� ������ �� ��������
					 i++; //����������� ������ ��� ������ ���������� �������
				 }
         
				f2.close(); //��������� ������ � ������
				S1 = S2;
//				cout<<S2<<endl; //������ ���������� char[] �������� ����� �� �����

		  	delete []S2; //����������� ������
			/**************************************/
			switch (Chislo)  //���� ��� ������ ���������� ����� ����
			{                //����� ����� ���������� � �������� ����������
							 //��� ����������� � �������� ���������

                case 2:
						break;
				case 1:	{   // TX;
							 while (S1.Pos(word_before))
							  {
									char buf1[100]= " ";
									int j=0;
									i=(S1.Pos(word_before)) ? (S1.Pos(word_before)+strlen(word_before)) : 0;
									int M = S1.Pos(word_before); //������ ������ ����� � � ������ ���������� ����� �����
									int L = S1.Length(); //������ ����� ������

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
								   //buf = buf.Insert((S1.SubString(S1.Pos("�����:")+8,5)),(S1.Pos("�����:")+8));
									S1 = S1.SubString(S1.Pos(word_before)+strlen(buf1)-1+strlen(word_before),S1.Length()-(S1.Pos(word_before)+strlen(word_before)+strlen(buf1)-2));
								   //-1 � -2 � ���� ������������ ���������� ��� ����������� ����������� ������ �������� \r \n
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
