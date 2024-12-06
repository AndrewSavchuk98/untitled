#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// THREAD  - ПОТОКИ



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
    cout << "..."<<endl;
}

int main() {
    string user;
    bool flag = true;

    thread t1([&] {
        user = doSomething(flag);
    });

    showProgress(flag);

    t1.join();
    cout << user << endl;

    return 0;
}

