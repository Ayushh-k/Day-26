#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int priority;
    node *next;

    node(int d, int p) : data(d), priority(p), next(NULL) {};
};

struct Queue
{
    node *front = NULL;
    node *rear = NULL;
};

bool isempty(Queue &q)
{
    return q.front == NULL;
}

void enqueue(Queue &q, int d, int p)
{
    node *newnode = new node(d, p);
    if (isempty(q) || q.front->priority < p)
    {
        newnode->next = q.front;
        q.front = newnode;
        if (q.rear == NULL)
        {
            q.rear = newnode;
        }
        return;
    }

    node *temp = q.front;

    while (temp->next != NULL && temp->next->priority >= p)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

pair<int, int> dequeue(Queue &q)
{
    pair<int, int> ans;
    if (isempty(q))
    {
        cout << "Queue underflow" << endl;
        ans = make_pair(INT_MIN, INT_MIN);
        return ans;
    }

    int item = q.front->data;
    int p = q.front->priority;
    ans = make_pair(item, p);
    node *temp = q.front;
    q.front = q.front->next;
    delete temp;
    return ans;
}

int main()
{
    Queue q;
    int max_size;
    cout << "Enter the size of Queue: ";
    cin >> max_size;

    for (int i = 0; i < max_size; i++)
    {
        int ele, priority;
        cin >> ele >> priority;
        enqueue(q, ele, priority);
    }

    while (!isempty(q))
    {
        pair<int, int> ans = dequeue(q);
        cout << "Dequeue element are : " << ans.first << " with Priority " << ans.second << endl;
    }
    return 0;
}