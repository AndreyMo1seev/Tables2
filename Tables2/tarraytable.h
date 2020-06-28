#ifndef _arraytable_h
#define _arraytable_h

#include "table.h"

#define TabMaxSize 25

enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };

class TArrayTable : public TTable {

protected:
	//TTabRecord *pRecs;
	int TabSize; //���� ����. ���-�� �������
	int CurrPos; //����� ������� ������� (��������� � 0)

public:
	TTabRecord* pRecs; // ������ ��� ������� �������
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

	//�������������� ������
	virtual int IsFull() const { //������� ���������?
		return DataCount >= TabSize;
	}

	int GetTabSize() const { //���-�� �������
		return TabSize;
	}
	//������
	virtual TKey GetKey(void) const { //����
		return GetKey(CURRENT_POS);
	}
	virtual TValue GetValuePtr(void) const { // ��������� �� ��������
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