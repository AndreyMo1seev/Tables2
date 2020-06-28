#define _CRT_SECURE_NO_WARNINGS
#include "tscantable.h"
#include "tsorttable.h"
#include "ttreetable.h"
#include "tarrayhash.h"
#include <random>
#include <string>

enum TTabMode { SCAN_TABLE = 1, SORT_TABLE, TREE_TABLE, HASH_TABLE };
TTable* pTab = NULL;
int* pKeys = NULL;
string* pVals = NULL;
int DataCount = 0;
int MemSize;
//int k
//TTable* pTab = NULL;
//string* pVals = NULL;

void TableGenerator(TTabMode mode)
{
	int  MaxKeyValue;
	cout << "Input the record's number - ";
	cin >> DataCount;
	cout << "Input the Maximum Key Value - ";
	cin >> MaxKeyValue;
	MemSize = DataCount * 3;
	switch (mode)
	{
	case SCAN_TABLE:
		pTab = new TScanTable(MemSize);
		break;
	case SORT_TABLE:
		pTab = new TSortTable(MemSize);
		break;
	case TREE_TABLE:
		pTab = new TTreeTable();
		break;
	case HASH_TABLE:
		pTab = new TArrayHashTable(MemSize);
		break;
	}
	pKeys = new int[MemSize];
	pVals = new string[MemSize];
	for (int i = 0; i < DataCount; i++)
	{
		pKeys[i] = rand() % MaxKeyValue;
		pVals[i] = "***" + to_string(pKeys[i]) + "***";
		pTab->InsRecord(pKeys[i], pVals[i]);
	}
	//cout << " Efficiency  = " << pTab->GetEfficiency() << endl;
	pTab->ClearEfficiency();
}

void TableProcessor(TTabMode mode) {
	int key;
	int com;
	string rec;
	while (1) {
		cout << "0 - Exit, 1 - Find, 2 - Insert, 3 - Delete, 4 - Print - ";
		cin >> com;
		if (com == 0)
			break;
		if (com == 1) {
			pTab->SetEfficiency(0);
			cout << "Input the key of record - ";
			cin >> key;
			cout << " Find " << pTab->FindRecord(key) << endl;
			cout << " Efficiency  = " << pTab->GetEfficiency() << endl;
		}
		if (com == 2) {
			pTab->ClearEfficiency();
			cout << "Input the key of record - ";
			cin >> key;
			cout << "Input the record - ";
			cin >> rec;
			if (DataCount >= MemSize)
				cout << "MemBuffer is full" << endl;
			else {
				pKeys[DataCount] = key;
				pVals[DataCount] = rec;
				pTab->InsRecord(key, pVals[DataCount]);
				DataCount++;
			}
			cout << " Efficiency  = " << pTab->GetEfficiency() << endl;
		}
		if (com == 3) {
			pTab->ClearEfficiency();
			cout << "Input the key of record - ";
			cin >> key;
			pTab->DelRecord(key);
			cout << " Efficiency  = " << pTab->GetEfficiency() << endl;
		}
		if (com == 4) {
			pTab->SetEfficiency(0);
			if (mode != TREE_TABLE)
				cout << *pTab;
			else
				((TTreeTable*)pTab)->Draw();
			//cout << " Efficiency  = " << pTab->GetEfficiency() << endl;
		}
	}
}

int main() {
	int TableType;

	cout << "1 - Scan, 2 - Sort, 3 - Tree, 4 - Hash: ";
	cin >> TableType;
	TableGenerator((TTabMode)TableType);
	TableProcessor((TTabMode)TableType);
}