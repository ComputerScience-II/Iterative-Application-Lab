#include <iostream>
#include <vector>
#include <functional>
#include <cassert>

using namespace std;


class Vectors {

private: 

    vector<int> a;
    function<int(int)> f;


public:

    Vectors(const vector<int>& a, function<int(int)> f) : a(a), f(f) {}

    void printVector() const {
       
        for ( int x : a ) {

            cout << x << " ";

        }

        cout << endl;

    }

    void apply() {

        for (int &x : a) {
            
            x = f(x);

        }

    }

    void apply_at(int n) {

        if (n >= 0 && n < a.size()){

            a[n] = f(a[n]);
        
        }

    }

    void apply_range(int start, int end) {

        if (start < 0) start = 0;

        if (end >= a.size()) end = a.size() - 1;

        for (int i = start; i <= end; ++i) {
            
            a[i] = f(a[i]);

        }

    }

    void apply_range(int start) {

        apply_range(start, a.size() - 1);

    }

    int get(int n) const {

        return a[n];

    }


};

int main() {

    Vectors v({1, 2, 3, 4, 5}, [](int x) { return x * x; });

    v.printVector(); 

    v.apply(); 

    cout << "\n";

    v.printVector(); 

    v.apply_at(2);

    cout << "\n";

    v.printVector();

    v.apply_range(1, 3);

    cout << "\n";

    v.printVector(); 

    v.apply_range(2);

    cout << "\n";

    v.printVector(); 

    cout << "\n";
    

    assert(v.get(0) == 1);

    assert(v.get(1) == 16);

    assert(v.get(2) == 43046721);

    assert(v.get(3) == 65536);

    assert(v.get(4) == 625);


    cout << "The code is good" << endl;

    return 0;




}
