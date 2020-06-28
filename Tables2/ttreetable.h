#ifndef _treetable_h
#define _treetable_h
#include <stack>
#include "table.h"
#include "ttreenode.h"

class TTreeTable : public TTable
{
protected:
	TTreeNode* pRoot; //указатель на корень дерева
	TTreeNode* ppRef; //адресс указателя на вершину результата в FindRecord
	TTreeNode* pCurrent; //указатель на текущую вершину
	int CurrPos; //номер текущей вершины
	TTreeNode* pPrev;
	stack<TTreeNode*> St; //Стек для иттератора

	void PrintTreeTable(ostream& os, TTreeNode* pNode); //печать
	void DrawTreeTable(TTreeNode* pNode, int Level);//печать с ярусами
	void DeleteTreeTable(TTreeNode* pNode);// удаление
public:
	TTreeTable() : TTable() {
		CurrPos = 0; pRoot = pCurrent = NULL; ppRef = NULL;
	}
	~TTreeTable() { DeleteTreeTable(pRoot); }
	//информационные методы
	virtual int IsFull() const; //заполнена?

	//основные методы
	virtual bool FindRecord(TKey k);//найти запись
	virtual int InsRecord(TKey k, TValue pVal); //вставить
	virtual int DelRecord(TKey k);//удалить запись
	//навигация
	virtual int Reset(void);//установить на первую запись
	virtual int IsTabEnded(void) const;//таблица завершена?
	virtual int GoNext(void);//переход к следующей записи
	//доступ
	virtual TKey GetKey(void) const; //ключ текущей записи
	virtual TValue GetValuePtr(void) const; //указатель на значение
	//печать таблицы
	friend ostream& operator<<(ostream& os, TTreeTable& tab);
	void Draw(void); //

/*
		TTreeTable() : TTable() {
		CurrPos = 0; pRoot = pCurrent = NULL; ppRef = NULL;
	}
	~TTreeTable() { DeleteTreeTable(pRoot); }
*/
};

#endif 