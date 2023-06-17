#include <iostream>
#include <vector>

using namespace std;

char get_user_value() {
    char value;
    cin >> value;
    return value;
}

template <typename type>
void print_msg(type msg) {
    cout << msg;
}

template <typename type>
void print_array_elements(const vector<type>& array, int row = 10) {
    unsigned int array_size = array.size();
    for (int i = 0; i < array_size; ++i) {
        if (i % row == 0) {
            cout << endl << "\t";
        }
        cout << array[i] << ' ';
    }
}

vector<int> find_intervals(const vector<char>& array, const char input) {
    vector<int> result;
    int counter = 0;
    unsigned int array_size = array.size();    

    for (auto& c : array) {
        if (c == input) {
            result.push_back(counter);
            counter = 0;
        }
        else
        {
            ++counter;
        }
    }

    result.erase(result.begin());
    return result;
}

int main()
{
    char user_value;
    vector<int> intervals;
    const vector<char> CHAR_ARRAY {
        'X', 'W', 'O', 'T', 'Z', 'Y', 'Q', 'V', 'U', 'T', 'Z', 'Y', 'X', 'W', 'O', 'T',
        'Z', 'Y', 'Q', 'V', 'U', 'T', 'S', 'X', 'W', 'V', 'N', 'Z', 'Y', 'X', 'P', 'U',
        'T', 'Z', 'R', 'W', 'V', 'U', 'M', 'Y', 'X', 'W', 'O', 'T', 'Z', 'Y', 'Q', 'V',
        'U', 'T', 'S', 'X', 'W', 'V', 'N', 'Z', 'Y', 'X', 'P', 'U', 'T', 'Z', 'R', 'W',
        'V', 'U', 'M', 'Y', 'X', 'W', 'O', 'T', 'Z', 'Y', 'Q', 'V', 'U', 'T', 'S', 'X',
        'W', 'V', 'N', 'Z', 'Y', 'X', 'P', 'U', 'T', 'Z'
    };

    print_msg("Array\n{");
    print_array_elements(CHAR_ARRAY);
    print_msg("\n}\n\n");
    print_msg("Enter the letter from array to find the intervals: ");

    user_value = get_user_value();
    intervals = find_intervals(CHAR_ARRAY, user_value);

    print_msg("Intervals for ");
    print_msg(user_value);
    print_msg(" in array: ");    
    print_array_elements(intervals, 6);

    return 0;
}