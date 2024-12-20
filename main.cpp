#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// THREAD  - ПОТОКИ

//test

string doSomething(bool &flag) {
    this_thread::sleep_for(chrono::seconds(4));
    string user = "user";
    flag = false;
    return user;
}

void showProgress(const bool &flag) {
    for (int i = 0; flag; i++) {
        cout << "wait... "<<  i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int helpMe(int a, int b) {
    return a * b;
}

int sum(int a, int b) {
    return a + b;
}

int main() {
    string user;
    bool flag = true;
    std::cout << "Hello World!\n";
    thread t1([&] {
        user = doSomething(flag);
    });

    showProgress(flag);

    t1.join();
    cout << user << endl;

    return 0;
}

