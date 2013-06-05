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
	///������ �� ��������� ��������� ����
    LinksMap links;
	///���������� ��������� ��� ������� ������. 
    Header *fail;  
	///��������� ������������ ���������. 
    Header *term; 
	///������ ��������� ���������
    int out;
	
	///�����������
    Header(Header *fail_node = NULL)
        : fail(fail_node)
        , term(NULL) 
        , out(-1)
    { 
	}
 
	///�������� ������ ��� Header �� ������
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
 
	///���������� �����y ���� ���� � �������� ���������
    bool isTerminal() const 
    {
        return (out >= 0);
    }
};