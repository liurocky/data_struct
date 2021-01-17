#include <iostream>
#include <vector>
using namespace std;

template <class T>
class cycleQueue
{
private:
    unsigned int m_size;
    int m_front;
    int m_rear;
    vector<T> m_data;
public:
    T& get(int i) {
        return m_data[i];
    }
    cycleQueue(unsigned size)
        :m_size(size),
        m_front(0),
        m_rear(0)
    {
        m_data.resize(size);
    }

    ~cycleQueue()
    {
        //delete[] m_data;
    }

    bool isEmpty()
    {
        return m_front == m_rear;
    }

    bool isFull()
    {
        return m_front == (m_rear + 1) % m_size;
    }

    void push(T ele)throw(bad_exception)
    {
        if (isFull())
        {
            pop();
        }
        m_data[m_rear] = ele;
        m_rear = (m_rear + 1) % m_size;
        cout << m_front << " " << m_rear << " " ;
        for (int i = 0; i < m_data.size(); i++) {
            cout << m_data[i] << ",";
        } 
        cout << endl;
    }

    T pop() throw(bad_exception)
    {
        if (isEmpty())
        {
            throw bad_exception();
        }
        T tmp = m_data[m_front];
        m_front = (m_front + 1) % m_size;
        return tmp;
    }
};


int main()
{
 
    cycleQueue<int> q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    int a = q.get(1);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    return 0;
}