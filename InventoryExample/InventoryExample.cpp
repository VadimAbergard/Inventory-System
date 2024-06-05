// InventoryExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Inventory.cpp"

int main()
{
    Inventory inv;

    int count = 3;
    int count2 = 7;
    inv.setItem(0, Item(ItemType::apple, 3));
    inv.addItemInSlot(9, Item(ItemType::apple), count2);
    //bool iRemove = inv.removeItem(Item(ItemType::apple), 6);
    //int count2 = 1;
    //inv.addItem(Item(ItemType::stone), count2);

    cout << "= " << count2 << endl;
    //cout << "isremove = " << iRemove << endl;

    inv.printConsole();
}