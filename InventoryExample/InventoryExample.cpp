// InventoryExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Inventory.cpp"

int main()
{
    Inventory inv; // create inventory

    int count = 7; // return result from method addItemInSlot
    inv.setItem(0, Item(ItemType::apple, 3)); 
    inv.addItemInSlot(9, Item(ItemType::apple), count);

    cout << "= " << count << endl; // we look at how many items are left in the inventory when we put them there

    inv.printConsole(); // we display the inventory in the console
}
