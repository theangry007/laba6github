#include "Aho-corasick.h"
 
int main()
{
	///��������� ���������� ������
    AhoCorasick aho; 
	///��������� ������ ��� ������
    aho.addString("IU");
    aho.addString("Zel");
    aho.addString("kiy");
	///�������������� ������ ������ ���
    aho.init(); 
	///���� ��������� � ������
    aho.search("Zelinskiy. Group: IU8-24"); 	
    system("pause");
    return 0;
}