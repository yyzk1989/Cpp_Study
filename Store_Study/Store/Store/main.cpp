#include "pch.h"
#include "Store.h"
using namespace std;

int main()
{
	STOREMANAGER.Init();

	int Req;
	int nType = 0;
	int nTid = 0;
	int nCount = 0;
	int nRemain = 0;

	bool bStart = true;;
	while (bStart)
	{
		
		cout << "���� (1), �� ���� Ȯ��(2), ���Ժ� ��� ���� Ȯ��(3), ����(99):";
		cin >> Req;

		switch (Req)
		{
			case 1:
			{
				cout << "���� Ÿ�� �������(1), ������(2), �������(3) :";
				cin >> nType;

				if (nType >= static_cast<int>(eStoreType::Max))
					continue;

				cout << "������ ID :";
				cin >> nTid;
				cout << "���� :";
				cin >> nCount;

				if (STOREMANAGER.Buy(static_cast<eStoreType>(nType), nTid, nCount, nRemain))
				{
					cout << "������ ID :" << nTid << endl;
					cout << "���� ���� : " << nCount << endl;
					cout << "������ ���� ���� : " << nRemain << endl;
					cout << "----------------------------" << endl;
					cout << endl;
				}
				else
				{
					cout << "������ ID :" << nTid << endl;
					cout << "������ ���� ����" << endl;
					cout << "������ ���� ���� :" << nTid << endl;
					cout << "----------------------------" << endl;
					cout << endl;
				}
				break;
			}
			case 2:
			{
				cout << "���� Ÿ�� :";
				cin >> nType;

				if (nType >= static_cast<int>(eStoreType::Max))
					continue;

				cout << "������ ID :";
				cin >> nTid;

				std::map<int, int> map_RemainList;

				STOREMANAGER.RemainList(static_cast<eStoreType>(nType), nTid, map_RemainList);

				for (auto iter : map_RemainList)
				{
					cout << "������ ID : " << iter.first << " ���� ���� : " << iter.second << endl;
				}

				cout << "----------------------------" << endl;
				cout << endl;

				break;
			}
			case 3:
			{
				cout << "���� Ÿ�� :";
				cin >> nType;

				std::map<int, int> map_RemainList;
				STOREMANAGER.StoreAllRemainList(static_cast<eStoreType>(nType), map_RemainList);

				for (auto iter : map_RemainList)
				{
					cout << "������ ID : " << iter.first << " ���� ���� : " << iter.second << endl;
				}

				cout << "----------------------------" << endl;
				cout << endl;
				break;
			}
			case 99:
			{
				bStart = false;
				break;
			}
		}
	};

	return 0;
}
