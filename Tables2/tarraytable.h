#ifndef _arraytable_h
#define _arraytable_h

#include "table.h"

#define TabMaxSize 25

enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };

class TArrayTable : public TTable {

protected:
	//TTabRecord *pRecs;
	int TabSize; //макс возм. кол-во записей
	int CurrPos; //номер текущей позиции (нумерация с 0)

public:
	TTabRecord* pRecs; // память для записей таблицы
	//TArrayTable() {};
	TArrayTable(int Size = TabMaxSize) {
		pRecs = new TTabRecord[Size];
		TabSize = Size;
		DataCount = CurrPos = 0;
	}
	virtual ~TArrayTable() {
		for (int i = 0; i < DataCount; i++)
			delete[] pRecs;
	}

	//информационные методы
	virtual int IsFull() const { //таблицы заполнена?
		return DataCount >= TabSize;
	}

	int GetTabSize() const { //кол-во записей
		return TabSize;
	}
	//доступ
	virtual TKey GetKey(void) const { //ключ
		return GetKey(CURRENT_POS);
	}
	virtual TValue GetValuePtr(void) const { // указатель на значение
		return GetValuePtr(CURRENT_POS);
	}
	virtual TKey GetKey(TDataPos mode) const;
	virtual TValue GetValuePtr(TDataPos mode) const;

	//navigation
	virtual int Reset(void);
	virtual int IsTabEnded(void) const;
	virtual int GoNext(void);
	virtual int SetCurrentPos(int pos);
	int GetCurrentPos(void) const {
		return CurrPos;
	}

	friend TSortTable;
};
#endif