#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum class ItemType{none, apple, stone};

class Item {
private:
	ItemType type;
	string name;
	int maxCount;
	int count;

	void initItem(ItemType typeItem) {
		type = typeItem;
		switch (typeItem) {
		case ItemType::apple:
			name = "apple";
			maxCount = 3;
			break;
		case ItemType::stone:
			name = "stone";
			maxCount = 30;
			break;
		default:
			break;
		}
	}

	void interval(int& count) {
		if (count > maxCount) count = maxCount;
		else if (count < 0) count = 0;
	}

public:
	Item() {
		this->name = "none";
		this->maxCount = 0;
		this->count = 0;
		this->type = ItemType::none;
	}

	Item(ItemType typeItem, int count = 1) {
		initItem(typeItem);
		interval(count);
		this->count = count;
	}

	void setCount(int count) {
		this->count = count;
	}

	void addCount(int count) {
		this->count += count;
	}

	int getMaxCount() {
		return maxCount;
	}

	string getName() {
		return name;
	}

	int getCount() {
		return count;
	}

	ItemType getType() {
		return type;
	}
};