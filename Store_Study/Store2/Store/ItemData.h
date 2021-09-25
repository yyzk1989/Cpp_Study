#pragma once

struct ItemInfo
{
	int CharUID;
	int TID;
	int Count;
	eItemType Type;
	bool bStack = false;
};

class ItemData
{
	ItemData() {};
	virtual ~ItemData() {};

	void clear()
	{
		pItemInfo->CharUID = 0;
		pItemInfo->TID = 0;
		pItemInfo->Count = 0;
		pItemInfo->Type = eItemType::None;
		pItemInfo->bStack = false;
	}

protected:
	ItemInfo* pItemInfo;
};


class EquipItem : ItemData
{
	EquipItem();
	virtual ~EquipItem();
public:
	eEquipType Equiptype;
};

class PotionItem : ItemData
{
	PotionItem();
	virtual ~PotionItem();
public:

};

class MaterialItem : ItemData
{
	MaterialItem();
	virtual ~MaterialItem();
public:
};
