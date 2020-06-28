#ifndef __ARRHASH_H__
#define __ARRHASH_H__

#include "thashtable.h"
#define TabHashStep  7

class TArrayHashTable : public THashTable {

protected:
	TTabRecord* pRecs; //память для записей таблицы
	int TabSize; //максимально возможное кол-во записей 
	int HashStep; //шаг вторичного перемешивания
	int FreePos; //первая свободная строка, обнаруженная при поиске 
	int CurrPos; //строка памяти при завершении поиска
	TTabRecord Mark; //маркер для индикации строк с удаленными записями 
	TTabRecord Empty;
	// функция открытого перемешивания
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }
public:
	TArrayHashTable(int Size = TabMaxSize, int Step = TabHashStep);
	virtual ~TArrayHashTable();
	//информационные методы
	virtual int IsFull() const { return DataCount >= TabSize; } //заполнена?
	//основные методы 
	virtual bool FindRecord(TKey k);//найти запись
	virtual int InsRecord(TKey k, TValue pVal);//вставить
	virtual int DelRecord(TKey k);// удалить запись
	//навигация
	virtual int Reset(void);//установить на перую запись
	virtual int IsTabEnded(void) const;//таблица завершена?
	virtual int GoNext(void);//переход к следующей записи 
	// (=1 после применения GoNext для последней записи)
	//доступ
	virtual TKey GetKey(void) const;// ключ текущей записи
	virtual TValue GetValuePtr(void) const; // указатель на значение 
};

#endif