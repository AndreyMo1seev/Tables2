#ifndef _record_h
#define _record_h
#include <iostream>
#include <string>
using namespace std;

typedef int TKey;
typedef string TValue;

class TTabRecord {

protected:
	TKey Key; // ключ записи
	virtual void Print(ostream& os) { os << Key << " " << pValue; }

public:
	TValue pValue; // указатель на значение
	//virtual void Print(ostream &os) { os << Key << " " << pValue; }
	TTabRecord(TKey k = 0, TValue pVal = "") { Key = k; pValue = pVal; }
	void SetKey(TKey k) { Key = k; }
	TKey GetKey(void) { return Key; }
	void SetValuePtr(TValue p) { pValue = p; }
	TValue GetValuePtr(void) { return pValue; }
	TTabRecord& operator=(TTabRecord& tr) {
		Key = tr.Key;
		pValue = tr.pValue;
		return *this;
	}

	virtual int operator==(const TTabRecord& tr) { return Key == tr.Key; }
	virtual int operator> (const TTabRecord& tr) { return Key > tr.Key; }
	virtual int operator< (const TTabRecord& tr) { return Key < tr.Key; }
	virtual int operator=(const TTabRecord& tr) { return Key = tr.Key; }
	virtual int operator!=(const TTabRecord& tr) { return Key != tr.Key; }

	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class TTreeNode;
	friend class TTreeTable;
	friend class THashTable;
	friend class TArrayHash;

};

#endif