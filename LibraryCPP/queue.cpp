#include "queue.h"
#include "list.h"

struct Queue
{
    List* list;
    ListItem* head;
    size_t tail;

    ~Queue() {
        list_delete(list);
    }
};

Queue *queue_create()
{
    Queue* queue = new Queue;
    queue->list = list_create();
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void queue_delete(Queue *queue)
{
    delete queue;
}

void queue_insert(Queue *queue, Data data)
{
    list_insert(queue->list, data);
    queue->tail++;
    queue->head = list_item_next(list_first(queue->list));    
}

Data queue_get(const Queue *queue)
{
    if (!queue_empty(queue))
    {
        return list_item_data(queue->head);
    }
    else
    {
        return Data();
    }
}

void queue_remove(Queue *queue)
{
    if (!queue_empty(queue))
    {
            list_erase(queue->list, list_item_next(list_first(queue->list)));
            queue->tail--;
            queue->head = list_item_next(list_first(queue->list));
    }
}

bool queue_empty(const Queue *queue)
{
    if (queue->tail == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
