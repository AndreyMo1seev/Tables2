#include "tscantable.h"

bool TScanTable::FindRecord(TKey k) { //найти запись
	int i;
	for (i = 0; i < DataCount; i++)
		if (pRecs[i].Key == k)
			break;
	Efficiency = i + 1;
	if (i < DataCount)
	{
		CurrPos = i;
		return true;
	}
	return false;
}
/*----------------------------------------------------------------------------------------------*/
int TScanTable::InsRecord(TKey k, TValue pVal)  // вставить запись
{
	if (IsFull())
	{
		cerr << " TabFull " << endl;
		return TabFull;
	}
	/*
	{
		cerr << "TabNoRec" << endl;
		return temp;
	}
	*/

	else if (FindRecord(k) == true)
	{
		cerr << " TabRecDbl " << endl;
		return TabRecDbl;
	}
	else
	{
		pRecs[DataCount].Key = k;
		pRecs[DataCount].pValue = pVal;
		DataCount++;
		Efficiency++;
	}
}
/*----------------------------------------------------------------------------------------------*/
int TScanTable::DelRecord(TKey k) //удалить запись
{
	int temp = FindRecord(k);
	if (temp == 0)
	{
		cerr << "TabNoRec" << endl;
		return temp;
	}
	else
	{
		pRecs[CurrPos] = pRecs[DataCount - 1];
		DataCount--;
		return TabOK;
	}
}