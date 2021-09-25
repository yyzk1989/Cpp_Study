#pragma once

class StoreManager
{
public:
	static StoreManager& GetIns(void)
	{
		static StoreManager instance;
		return instance;
	}
public:
	StoreManager();
	virtual ~StoreManager();

	bool Init(void);
	void Final(void);

	bool Buy(eStoreType eType, int nTid, int nCount, OUT int& nRemainCount);

	void RemainList(eStoreType eType, int nTid, OUT std::map<int,int>& SellList);
	void StoreAllRemainList(eStoreType eType, OUT std::map<int, int>& SellList);

private:
	class IStore
	{
	public:
		IStore(void) {};
		virtual ~IStore() = default;

	public:
		virtual void SetSellList(std::map<int, int>& mapList);
		virtual bool BuyTarget(int nTid, int nCount,OUT int& nRemainCount) = 0;
		virtual void GetSellList(int nTid, OUT std::map<int, int>& map_SellList);
		virtual void GetSellAllList(std::map<int, int>& map_SellList);
	public:
		std::map<int, int/*ItemTID, Count*/> SellList;
	};

	class WeaponStore :public IStore
	{
		friend class StoreManager;
	private:
		WeaponStore(void) {};
		virtual ~WeaponStore() = default;
		virtual bool BuyTarget(int nTid, int nCount, OUT int& nRemainCount);
	};

	class EquipStore :public IStore
	{
		friend class StoreManager;
	private:
		EquipStore(void) {};
		virtual ~EquipStore() = default;
		virtual bool BuyTarget(int nTid, int nCount, OUT int& nRemainCount);
	};

	class PotionStore :public IStore
	{
		friend class StoreManager;
	private:
		PotionStore(void) {};
		virtual ~PotionStore() = default;
		virtual bool BuyTarget(int nTid, int nCount, OUT int& nRemainCount);
	};

	std::map<eStoreType, IStore*> mapStore;
};

#define STOREMANAGER StoreManager::GetIns()