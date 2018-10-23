#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

template <typename T>
void quicksort(vector<T>& a, int p, int r);

template <typename T>
int partition(vector<T>& a, int p, int r);

template <typename T>
void display(const vector<T>& a){
    for(auto it = a.cbegin(); it != a.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    int max = 31, len = 20;
    default_random_engine random_engine;
    random_engine.seed(chrono::system_clock::now().time_since_epoch().count());    
    uniform_int_distribution<> distribution{1, max};
    
    vector<int> a;
    for(int i = 0; i < len; ++i){
        a.push_back(distribution(random_engine));
    }

    quicksort(a, 0, a.size() - 1);
    display(a);
    return 0;
}

template <typename T>
void quicksort(vector<T>& a, int p, int r){
    if(p < r){
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

template <typename T>
int partition(vector<T>& a, int p, int r){
    T x = a[r];
    int i = p - 1;
    for(auto j = p; j < r; ++j){
        if(a[j] < x){
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
