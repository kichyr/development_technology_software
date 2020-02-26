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
    if(is.fail() || vector_size < 0) {
        cout << "error" << endl;
        exit(1);
    }
    for (int i = 0; i < vector_size; i++) {
        is >> input;
        if(is.fail()) {
            cout << "error" << endl;
            exit(1);
        }
        v.push_back(input);
    }
    return is; 
}

//input sequence using cin, user should input size of sequence and its elements
//all elements of the sequence should be in range [0, M)
//function returns map that keys are just elements of sequence and value true
map<long long int, bool> get_input_numbers(long long int M) {
    int size, input;
    map<long long int, bool> input_numbers;
    cout << "enter sequense size:" << endl;
    cin >> size;
    if(cin.fail() || size < 0 || size >= M) {
        cout << "error" << endl;
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        cin >> input;
        if(cin.fail() || input >= M || input < 0)
            exit(1);
        input_numbers[input] = true;
    }
    return input_numbers;
}

//returns set that represents difference of sets: [0,1 ... M) and keys of the given map
vector<long long int> get_set_difference(long long int M, map<long long int, bool> input_numbers) {
    vector<long long int> diff;
    for(int i = 0; i < M; i++)
        if ( input_numbers.find(i) == input_numbers.end() )
            diff.push_back(i);
    return diff;
}

int main() {
    int M;
    cout << "enter M:" << endl;
    cin >> M;
    if(cin.fail()) {
        cout << "error" << endl;
        exit(1);
    }

    auto input_numbers = get_input_numbers(M);
    cout << get_set_difference(M, input_numbers);
}