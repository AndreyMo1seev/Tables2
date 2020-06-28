#ifndef __ARRHASH_H__
#define __ARRHASH_H__

#include "thashtable.h"
#define TabHashStep  7

class TArrayHashTable : public THashTable {

protected:
	TTabRecord* pRecs; //������ ��� ������� �������
	int TabSize; //����������� ��������� ���-�� ������� 
	int HashStep; //��� ���������� �������������
	int FreePos; //������ ��������� ������, ������������ ��� ������ 
	int CurrPos; //������ ������ ��� ���������� ������
	TTabRecord Mark; //������ ��� ��������� ����� � ���������� �������� 
	TTabRecord Empty;
	// ������� ��������� �������������
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }
public:
	TArrayHashTable(int Size = TabMaxSize, int Step = TabHashStep);
	virtual ~TArrayHashTable();
	//�������������� ������
	virtual int IsFull() const { return DataCount >= TabSize; } //���������?
	//�������� ������ 
	virtual bool FindRecord(TKey k);//����� ������
	virtual int InsRecord(TKey k, TValue pVal);//��������
	virtual int DelRecord(TKey k);// ������� ������
	//���������
	virtual int Reset(void);//���������� �� ����� ������
	virtual int IsTabEnded(void) const;//������� ���������?
	virtual int GoNext(void);//������� � ��������� ������ 
	// (=1 ����� ���������� GoNext ��� ��������� ������)
	//������
	virtual TKey GetKey(void) const;// ���� ������� ������
	virtual TValue GetValuePtr(void) const; // ��������� �� �������� 
};

#endif