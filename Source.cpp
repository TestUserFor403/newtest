#include <iostream>
#include <thread>
using namespace std;

void f(int& n) {
    for (int i = 0; i < 5; ++i) {
        ++n;
        cout << this_thread::get_id() <<"\n";
    }
}

int main() {
    int n = 0;
    std::thread t(f, std::ref(n));
    std::cout << n;
    
    t.join();
    std::cout << n;
}
