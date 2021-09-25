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
		
		cout << "구매 (1), 각 수량 확인(2), 가게별 모든 수량 확인(3), 종료(99):";
		cin >> Req;

		switch (Req)
		{
			case 1:
			{
				cout << "가게 타입 무기상점(1), 장비상점(2), 물약상점(3) :";
				cin >> nType;

				if (nType >= static_cast<int>(eStoreType::Max))
					continue;

				cout << "아이템 ID :";
				cin >> nTid;
				cout << "수량 :";
				cin >> nCount;

				if (STOREMANAGER.Buy(static_cast<eStoreType>(nType), nTid, nCount, nRemain))
				{
					cout << "아이템 ID :" << nTid << endl;
					cout << "구매 수량 : " << nCount << endl;
					cout << "가게의 남은 수량 : " << nRemain << endl;
					cout << "----------------------------" << endl;
					cout << endl;
				}
				else
				{
					cout << "아이템 ID :" << nTid << endl;
					cout << "아이템 수량 부족" << endl;
					cout << "가게의 남은 수량 :" << nTid << endl;
					cout << "----------------------------" << endl;
					cout << endl;
				}
				break;
			}
			case 2:
			{
				cout << "가게 타입 :";
				cin >> nType;

				if (nType >= static_cast<int>(eStoreType::Max))
					continue;

				cout << "아이템 ID :";
				cin >> nTid;

				std::map<int, int> map_RemainList;

				STOREMANAGER.RemainList(static_cast<eStoreType>(nType), nTid, map_RemainList);

				for (auto iter : map_RemainList)
				{
					cout << "아이템 ID : " << iter.first << " 남은 수량 : " << iter.second << endl;
				}

				cout << "----------------------------" << endl;
				cout << endl;

				break;
			}
			case 3:
			{
				cout << "가게 타입 :";
				cin >> nType;

				std::map<int, int> map_RemainList;
				STOREMANAGER.StoreAllRemainList(static_cast<eStoreType>(nType), map_RemainList);

				for (auto iter : map_RemainList)
				{
					cout << "아이템 ID : " << iter.first << " 남은 수량 : " << iter.second << endl;
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
