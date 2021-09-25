#include "pch.h"
#include "Store.h"

StoreManager::StoreManager()
{

}
StoreManager::~StoreManager()
{
	Final();
}

bool StoreManager::Init(void)
{
	{
		auto [iter, res] = mapStore.emplace(eStoreType::Weapon, new WeaponStore());
		if (res)
		{
			std::map<int, int> tmpList;
			tmpList.insert({ 10, 1000 });
			tmpList.insert({ 20, 1000 });
			tmpList.insert({ 30, 1000 });
			tmpList.insert({ 40, 1000 });

			iter->second->SetSellList(tmpList);
		}
	}

	{
		auto [iter, res] = mapStore.emplace(eStoreType::Equip, new EquipStore());
		if (res)
		{
			std::map<int, int> tmpList;
			tmpList.insert({100, 1000});
			tmpList.insert({200, 1000});
			tmpList.insert({300, 1000});
			tmpList.insert({400, 1000});

			iter->second->SetSellList(tmpList);
		}
	}

	{
		auto [iter, res] = mapStore.emplace(eStoreType::Potion, new PotionStore());
		if (res)
		{
			std::map<int, int> tmpList;
			tmpList.insert({2000, 1000});
			tmpList.insert({3000, 1000});
			tmpList.insert({4000, 1000});
			tmpList.insert({1000, 1000});

			iter->second->SetSellList(tmpList);
		}
	}


	return true;
}
bool StoreManager::Buy(eStoreType eType, int nTid, int nCount, OUT int& nRemainCount)
{
	auto iterShop = mapStore.find(eType);
	if (iterShop == mapStore.end())
		return false;

	if (!iterShop->second->BuyTarget(nTid, nCount, nRemainCount))
		return false;

	return true;
}

void StoreManager::RemainList(eStoreType eType, int nTid, OUT std::map<int, int>& SellList)
{
	auto iterShop = mapStore.find(eType);
	if (iterShop == mapStore.end())
		return;

	iterShop->second->GetSellList(nTid, SellList);
}

void StoreManager::StoreAllRemainList(eStoreType eType, OUT std::map<int, int>& SellList)
{
	auto iterShop = mapStore.find(eType);
	if (iterShop == mapStore.end())
		return;

	iterShop->second->GetSellAllList(SellList);
}

void StoreManager::Final(void)
{
	for (auto& iter : mapStore)
	{
		SAFE_DELETE(iter.second);
	}
}

void StoreManager::IStore::SetSellList(std::map<int, int>& mapList)
{
	SellList = std::move(mapList);	
}

bool StoreManager::IStore::BuyTarget(int nTid, int nCount, OUT int& nRemainCount)
{
	auto iter = SellList.find(nTid);
	if (iter == SellList.end())
		return false;

	if (iter->second >= nCount)
	{
		iter->second -= nCount;
		nRemainCount = iter->second;
	}
	else
	{
		nRemainCount = iter->second;
		return false;
	}

	return true;
}

void StoreManager::IStore::GetSellList(int nTid, OUT std::map<int, int>& map_SellList)
{
	auto iter = SellList.find(nTid);
	if (iter == SellList.end())
		return;

	map_SellList.insert({ iter->first, iter->second });
}

void StoreManager::IStore::GetSellAllList(std::map<int, int>& map_SellList)
{
	for (auto iter : SellList)
	{
		map_SellList.insert({ iter.first, iter.second });
	}
}

bool StoreManager::WeaponStore::BuyTarget(int nTid, int nCount, OUT int& nRemainCount)
{
	if (!IStore::BuyTarget(nTid, nCount, nRemainCount))
		return false;
	
	// 상점마다 다른 기능 구현 할 수 있도록
	return true;
}

bool StoreManager::EquipStore::BuyTarget(int nTid, int nCount, OUT int& nRemainCount)
{
	if (!IStore::BuyTarget(nTid, nCount, nRemainCount))
		return false;

	// 상점마다 다른 기능 구현 할 수 있도록
	return true;
}

bool StoreManager::PotionStore::BuyTarget(int nTid, int nCount, OUT int& nRemainCount)
{
	if (!IStore::BuyTarget(nTid, nCount, nRemainCount))
		return false;

	// 상점마다 다른 기능 구현 할 수 있도록
	return true;
}

