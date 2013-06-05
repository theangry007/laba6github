#include "Aho-corasick.h"
 
int main()
{
	///Объявляем переменную класса
    AhoCorasick aho; 
	///Добавляем строки для поиска
    aho.addString("IU");
    aho.addString("Zel");
    aho.addString("kiy");
	///Инициализируем дерево поиска бор
    aho.init(); 
	///Ищем подстроки в строке
    aho.search("Zelinskiy. Group: IU8-24"); 	
    system("pause");
    return 0;
}