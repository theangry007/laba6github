#pragma once
#include "Header.h"

using namespace std;
/**
AhoCorasic

Алгоритм Ахо-Корасика для строк
*/
class AhoCorasick
{
public:
	///Корень
    Header root;
	///Искомые слова
    vector<string> words;
	///Текущее состояние в дереве Бор
    Header* current_state; 

	///Добавить строку для поиска
    void addString(const char* const str) 
    {
        Header *current_node = &root;
        for(const char *cp = str; *cp; ++cp) {
            Header *child_node = current_node->getLink(*cp);
            if (!child_node) {
                child_node = new Header(&root);
                current_node->links[*cp] = child_node;
            }
            current_node = child_node;
        }
        current_node->out = words.size();
        words.push_back(str);
    }
 
	///Строит дерево поиска бор с искомыми словами
    void init() 
    {
        queue<Header *> q;
        q.push(&root);
        while (!q.empty()) {
            Header *current_node = q.front();
            q.pop();
            for (LinksMap::const_iterator iter = current_node->links.cbegin();
                 iter != current_node->links.cend(); ++iter)
            {
                const char symbol = iter->first;
                Header *child = iter->second;               
                Header *temp_node = current_node->fail;
                while (temp_node) {
                    Header *fail_candidate = temp_node->getLink(symbol);
                    if (fail_candidate) {
                        child->fail = fail_candidate;
                        break;
                    }
                    temp_node = temp_node->fail;
                } 
                    if (child->fail->isTerminal()) {
                        child->term = child->fail;
                    }
                    else {
                        child->term = child->fail->term;
                    }
                q.push(child);
            }
        }
    } 
 
	///Поиск конечных состояний для символа, если находит, то возвращает это состояние
    void step(const char c) 
    {
        while (current_state) {
            Header *candidate = current_state->getLink(c);
            if (candidate) {
                current_state = candidate;
                return;
            }
            current_state = current_state->fail;
        }
        current_state = &root;
    } 
 

	///Ищет подстроку в строке
    void search(const char* str) 
    {
        current_state = &root;
        for(; *str; ++str) 
		{
            cout << *str << endl;
            step(*str);
            if (current_state->isTerminal())
			{
				print(words[current_state->out].c_str());
			}
			Header *temp_node = current_state->term;
			while (temp_node)
			{
				print(words[temp_node->out].c_str()); 
				temp_node = temp_node->term;
			}
		}
    }

	///Печать найденной строки
	void print(const char* str)
	{
		cout << ">>>> \""<< str <<"\" found" << "\n";
	}
};
