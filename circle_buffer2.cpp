#include <vector>
#include <iostream>
using namespace std;


template <class T>
class CircularBuffer {
    int front_;
    int tail_;
    std::vector<T> data_;
public:
    CircularBuffer(int size) {
        data_.resize(size);
        front_ = tail_ = 0;
    }

    void push(const T& t) {
        if (is_full()) pop();
        data_[tail_] = t;
        tail_ = (tail_ + 1) % data_.size();
        cout << front_ << "," << tail_ << " ";
        for (int i = 0; i < data_.size(); i++) {
            cout << data_[i] << ",";
        }
        cout << endl;
    }

    void pop() {
        front_ = (front_ + 1) % data_.size();
    }   

    bool is_full() {
        return front_ == (tail_ + 1) % data_.size();
    }

    T& front() {
        return data_[front_];
    }

    T& tail() {
        return tail_==0 ? data_.back() : data_[tail_-1];
    }
};


void highoid(int64_t* hoid, int64_t city, int64_t loid) {
    int64_t highpart = (loid >> 32);
    int64_t lowpart = (loid & 0xffffffff);
    *hoid = (highpart << 46) + (city << 32) + lowpart;
}

int main(int argc, char** argv) {
    int64_t hoid = 0;
    highoid(&hoid, 32, 35226033043099);
    CircularBuffer<int> cb(5);
    cb.push(0);
    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    return 0;
}