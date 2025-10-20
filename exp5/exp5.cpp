#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> div = {1,0,0,0,1,0};

    int n;
    cout << "Enter the number of bits: ";
    cin >> n;

    vector<int> data;
    for (int i = 0; i < n; i++) {
        int bit;
        cout << "Enter bit " << i + 1 << ": ";
        cin >> bit;
        data.push_back(bit);
    }

    int m = div.size();

    if (n < m) {
        cout << "Invalid data" << endl;
        return 0; 
    }

    
    vector<int> cdata = data;
    for (int i = 0; i < m - 1; i++) cdata.push_back(0);
      

    cout << "Initial codeword: ";
    for (int bit : cdata) cout << bit << " ";
    cout << endl;

   
    for (int i = 0; i < n; i++) {
        if (cdata[i] == 1) {
            for (int j = 0; j < m; j++) {
                cdata[i + j] ^= div[j];
            }
        }
    }

    
    for (int i = n; i < n + m - 1; i++) {
        data.push_back(cdata[i]);
    }

    cout << "Data to be transmitted is: ";
    for (int bit : data) cout << bit << " ";
    cout << endl;

    
    char ch;
    cout << "Introduce Error - Y->YES N->NO : ";
    cin >> ch;

    if (ch == 'Y'|| ch=='y') {
        int p;
        cout << "Enter the position to change bit (1-indexed): ";
        cin >> p;
        if (p - 1 < 0 || p - 1 > n + m - 2) {
            cout << "Invalid Position!!" << endl;
        }
        else {
           
            data[p - 1] ^= 1;
        }
    }

    cout << "The message received is: ";
    for (int bit : data) cout << bit << " ";
    cout << endl;

    
    for (int i = 0; i < n; i++) {
        if (data[i] == 1) {
            for (int j = 0; j < m; j++) {
                data[i + j] ^= div[j];
            }
        }
    }

    bool flag = true;
    for (int bit : data) {
        if (bit == 1) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "No error --> Successfully Transferred" << endl;
    else
        cout << "Error Detected" << endl;

    return 0;
}

