#include <iostream>
#include <string>

using namespace std;


bool like(string& s1, const string& s2) {

    
    for (size_t i = 0; i < s1.size() && i < s2.size(); ++i) {

        if ( s1[i] != '#' && s2[i] != '#' && s1[i] != s2[i] ) {
            return false;
        }

        else if (s1[i] == '#' && s2[i] != '#') {
            s1[i] = s2[i];
        }


    }


    return true;
}


int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int answer = 0;


    for (size_t i = 1;  i <= s.size() ; ++i  ) {

        string s1 = s.substr(0,i);

        bool result = true;

        size_t len = i;

        for (size_t j = len; j < s.size() ; j +=len) {

            string s2 = s.substr(j, len) ;

            if ( !like(s1,s2) ) {
                result = false;
                break;
            }
        }

        if (result) {
            answer = len;
            break;
        }

     //   cout << i << endl;
    }

    cout << answer << endl;


    return EXIT_SUCCESS;
}
