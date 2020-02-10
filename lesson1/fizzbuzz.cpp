#include <iostream>
#include <string>
#include <vector>

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

static bool check_devision_3(int num) {
    if(num == 0 || num == 3 || num == 6 || num == 9)
        return true;
    else if(num < 10)
        return false;

    string str_num = to_string(num);
    int sum = 0;
    for(int i = 0; i < str_num.size(); i++) {
        sum += str_num[i] - '0';
    }
    return check_devision_3(sum);
}

static bool check_devision_5(int num) {
    string str_num = to_string(num);
    if(str_num.back() == '0' || str_num.back() == '5')
        return true;
    return false;
}


//returns fizz if number is divisible by 3
//returns buzz if number is divisible by 5
//returns fizzbuzz if both and original number in other cases
static string fizzbuzz_number(int number) {
    if( check_devision_5(number) && check_devision_3(number))
        return "fizzbuzz";
    else if( check_devision_5(number) )
        return "fizz";
    else if( check_devision_3(number) )
        return "buzz"; 
    else
        return to_string(number);
}

int main() {
    vector<int> input_sequence;
    cin >> input_sequence;
    
    vector<string> fizzbuzzed_sequence;
    for (auto number : input_sequence)
        fizzbuzzed_sequence.push_back(fizzbuzz_number(number));

    cout << fizzbuzzed_sequence << endl;
    return 0;
}
