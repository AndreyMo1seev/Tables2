#ifndef _treetable_h
#define _treetable_h
#include <stack>
#include "table.h"
#include "ttreenode.h"

class TTreeTable : public TTable
{
protected:
	TTreeNode* pRoot; //��������� �� ������ ������
	TTreeNode* ppRef; //������ ��������� �� ������� ���������� � FindRecord
	TTreeNode* pCurrent; //��������� �� ������� �������
	int CurrPos; //����� ������� �������
	TTreeNode* pPrev;
	stack<TTreeNode*> St; //���� ��� ����������

	void PrintTreeTable(ostream& os, TTreeNode* pNode); //������
	void DrawTreeTable(TTreeNode* pNode, int Level);//������ � �������
	void DeleteTreeTable(TTreeNode* pNode);// ��������
public:
	TTreeTable() : TTable() {
		CurrPos = 0; pRoot = pCurrent = NULL; ppRef = NULL;
	}
	~TTreeTable() { DeleteTreeTable(pRoot); }
	//�������������� ������
	virtual int IsFull() const; //���������?

	//�������� ������
	virtual bool FindRecord(TKey k);//����� ������
	virtual int InsRecord(TKey k, TValue pVal); //��������
	virtual int DelRecord(TKey k);//������� ������
	//���������
	virtual int Reset(void);//���������� �� ������ ������
	virtual int IsTabEnded(void) const;//������� ���������?
	virtual int GoNext(void);//������� � ��������� ������
	//������
	virtual TKey GetKey(void) const; //���� ������� ������
	virtual TValue GetValuePtr(void) const; //��������� �� ��������
	//������ �������
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