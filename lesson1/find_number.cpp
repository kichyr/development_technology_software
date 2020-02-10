#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// C++ template to print vector container elements 
template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
}

// Template to input vector, first input vector size, then input sequence
template <typename T> 
istream& operator>>(istream& is, vector<T>& v) {
    T input;
    int vector_size;
    cout << "enter sequense size:" << endl;
    is >> vector_size;
    if(is.fail() || vector_size < 0)
        throw "wrong input";
    for (int i = 0; i < vector_size; i++) {
        is >> input;
        if(is.fail())
            throw "wrong input";
        v.push_back(input);
    }
    return is; 
}


map<int, bool> get_input_numbers(int M) {
    int size, input;
    map<int, bool> input_numbers;
    cout << "enter sequense size:" << endl;
    cin >> size;
    if(cin.fail() || size < 0 || size >= M)
        throw "wrong input";
    for (int i = 0; i < size; i++) {
        cin >> input;
        if(cin.fail() || input >= M || input < 0)
            throw "wrong input";
        input_numbers[input] = true;
    }
    return input_numbers;
}

vector<int> get_set_difference(int M, map<int, bool> input_numbers) {
    vector<int> diff;
    for(int i = 0; i < M; i++)
        if ( input_numbers.find(i) == input_numbers.end() )
            diff.push_back(i);
    return diff;
}

int main() {
    int M;
    cin >> M;
    if(cin.fail())
        throw "wrong input";

    auto input_numbers = get_input_numbers(M);
    cout << get_set_difference(M, input_numbers);
}