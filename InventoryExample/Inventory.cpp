#include <iostream>
#include "Item.cpp"

using namespace std;

class Inventory {
private:
	int size = 24;
	Item items[24];
public:
	Inventory() {
		items[5] = Item(ItemType::apple);
	}

	void setItem(int slot, Item item) {
		items[slot] = item;
	}

	void deleteItem(int slot) {
		items[slot] = Item();
	}

	void addItemInSlot(int slot, Item item, int& _count) {
		if (items[slot].getType() == item.getType()) {
			int count = items[slot].getMaxCount() - items[slot].getCount();
			if (count > _count) {
				items[slot].addCount(_count);
				_count = 0;
			}
			else if (count <= _count) {
				items[slot].addCount(count);
				_count -= count;
			}
		}
		else if (items[slot].getType() == ItemType::none) {
			items[slot] = Item(item.getType(), 0);
			int count = items[slot].getMaxCount();
			if (count > _count) {
				items[slot].addCount(_count);
				_count = 0;
			}
			else if (count <= _count) {
				items[slot].addCount(count);
				_count -= count;
			}
		}
	}

	bool removeItem(Item item, int _count) {
		bool hasItems = hasItem(item, _count);
		if (!hasItems) return false;

		for (int i = 0; i < size; i++) {
			if (items[i].getType() == item.getType()) {
				int count = items[i].getCount();
				if (count > _count) {
					items[i].addCount(-_count);
					_count -= count;
					if (_count <= 0)
						break;
				}
				else if (count <= _count) {
					items[i] = Item();
					_count -= count;
					if (_count <= 0)
						break;
				}
			}
		}

		return true;
	}

	void addItem(Item item, int& _count) {
		for (int i = 0; i < size; i++) {
			if (items[i].getType() == item.getType()) {
				if (items[i].getCount() != items[i].getMaxCount()) {
					int count = items[i].getMaxCount() - items[i].getCount();
					if (count > _count) {
						items[i].addCount(_count);
						_count -= count;
						if (_count <= 0)
							return;
					}
					else if (count <= _count) {
						items[i].addCount(count);
						_count -= count;
						if (_count <= 0)
							return;
					}
				}
			}
		}

		//добавляем этот предмет в инвентарь
		for (int i = 0; i < size; i++) {
			if (items[i].getType() == item.getType()) {
				if (items[i].getCount() != items[i].getMaxCount()) {
					int count = items[i].getMaxCount() - items[i].getCount();
					if (count > _count) {
						items[i].addCount(_count);
						_count -= count;
						if (_count <= 0) 
							break;
					}
					else if (count <= _count) {
						items[i].addCount(count);
						_count -= count;
					}
				}
			}
			else if (items[i].getType() == ItemType::none) {
				if (_count < item.getMaxCount()) {
					items[i] = item;
					items[i].setCount(_count);
					_count = 0;
					break;
				}
				else if (_count >= item.getMaxCount()) {
					items[i] = item;
					items[i].setCount(item.getMaxCount());
					_count -= item.getMaxCount();
					if (_count <= 0)
						break;
				}
			}
		}
	}

	bool hasItem(Item item, int _count) {
		int count = _count;
		for (int i = 0; i < size; i++) {
			if (items[i].getType() == item.getType()) {
				count -= items[i].getCount();
				if (count <= 0) {
					return true;
				}
			}
		}
		return false;
	}

	void printConsole() {
		for (int i = 0; i < size; i++) {
			cout << "slot " << i << "; " << items[i].getName() << ", max = " << items[i].getMaxCount() << ", count = " << items[i].getCount() << endl;
		}
	}
};