#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Header;
typedef map<const char, Header *> LinksMap;


class Header {
public:
	///Ссылки на возможных следующих букв
    LinksMap links;
	///Предыдущее состояние для функции отката. 
    Header *fail;  
	///Ближайшее терминальное состояние. 
    Header *term; 
	///Размер конечного состояния
    int out;
	
	///Конструктор
    Header(Header *fail_node = NULL)
        : fail(fail_node)
        , term(NULL) 
        , out(-1)
    { 
	}
 
	///Получить ссылку для Header на символ
    Header* getLink(const char c) const 
    {
        auto iter = links.find(c);
        if (iter != links.cend()) {
            return iter->second;
        }
        else {
            return NULL;
        }
    }
 
	///Возвращает истинy если узел в конечном состоянии
    bool isTerminal() const 
    {
        return (out >= 0);
    }
};