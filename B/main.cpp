// cl.exe main.cpp /EHsc /std:c++17 /Femain.exe

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Post { 
    int relevance;
    vector<bool> properties;

    Post(int r, const string& props) : relevance(r) {

        properties.reserve(props.size());

        for (char c : props) {
            properties.push_back(c == '1' ? true : false) ;
        }
    }
};

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<Post> posts;
    posts.reserve(n);

    for (int i = 0; i < n; ++i) {

        int r;
        string props;

        cin >> r >> props;
        posts.emplace_back(r, props);
    }

    vector<int> A;
    A.reserve(k);

    for (int i = 0; i < k; ++i) {

        int temp;
        cin >> temp;
        A.push_back(temp);
    }






    return EXIT_SUCCESS;
}