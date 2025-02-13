#include <cstddef>
#include "list.h"


struct ListItem
{
    Data field;
    ListItem* next;
    ListItem* prev;
};

struct List
{
    ListItem* first;
};

List* list_create()
{
    List* list = new List;
    list->first = nullptr;
    return list;
}

void list_delete(List* list)
{
     while (list->first)
    {
        list_erase(list, list->first);
    }
    delete list;
}

ListItem* list_first(List* list)
{
    return list->first;
}

Data list_item_data(const ListItem* item)
{
    if (item)
    {
        return item->field;
    }
    else
    {
        return Data();
    }
}

ListItem* list_item_next(ListItem* item)
{
    if (item)
    {
        return item->next;
    }
    else
    {
        return NULL;
    }
}

ListItem* list_item_prev(ListItem* item)
{
    if (item)
    {
        return item->prev;
    }
    else
    {
        return NULL;
    }
}

ListItem* list_insert(List* list, Data data)
{
    ListItem* item = new ListItem;
    item->field = data;

    if (!list->first)
    {
        list->first = item;
        list->first->next = item;
        list->first->prev = item;
    }
    else
    {
        item->prev = list->first->prev;
        item->next = list->first;
        list->first->prev->next = item;
        list->first->prev = item;
    }
    list->first = item;

    return item;
}

ListItem* list_insert_after(List* list, ListItem* item, Data data)
{
    if (list->first)
    {
        ListItem* newItem = new ListItem;
        newItem->field = data;
        newItem->prev = item;
        newItem->next = item->next;
        item->next->prev = newItem;
        item->next = newItem;
        return newItem;
    }
    else
    {
        return NULL;
    }
}
ListItem* list_erase(List* list, ListItem* item)
{
    ListItem* erase = nullptr;
    if (list->first)
    {
        if (item->next == item)
        {
            list->first = nullptr;
            erase = item;
            delete erase;
            return NULL;
        }
        else
        {
           ListItem* item_next = item->next;
            if (item == list->first)
            {
                list->first = list->first->next;
            }
            erase = item;
            (item->next)->prev = item->prev;
            (item->prev)->next = item->next;
            delete erase;
            return item_next;
        }
    }
    else
    {
        return NULL;
    }
}

ListItem* list_erase_next(List* list, ListItem* item)
{
    list_erase(list, list_item_next(item));
    return item;
}


