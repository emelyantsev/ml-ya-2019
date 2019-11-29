// cl.exe main.cpp /EHsc /std:c++17 /Femain.exe

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <cassert>

using namespace std;

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
} 

template <typename T> 
vector<T> operator+(const vector<T>& v1, const vector<T>& v2) 
{ 

    assert(v1.size() == v2.size()) ;

    vector<T> result;
    result.reserve(v1.size());

    for (int i = 0; i < v1.size(); ++i) { 
        
        result.push_back(v1[i] + v2[i]) ;
    } 
    
    return result; 
} 


template <typename T> 
vector<T> operator-(const vector<T>& v1, const vector<T>& v2) 
{ 

    assert(v1.size() == v2.size()) ;

    vector<T> result;
    result.reserve(v1.size());

    for (int i = 0; i < v1.size(); ++i) { 
        
        result.push_back(v1[i] - v2[i]) ;
    } 
    
    return result; 
} 

template <typename T> 
bool operator>=(const vector<T>& v1, const vector<T>& v2) 
{ 

    assert(v1.size() == v2.size()) ;

    bool result = true;

    for (int i = 0; i < v1.size(); ++i) { 
        
        if (v1[i] < v2[i]) {
            result = false;
            break;
        } 
        
    } 
    
    return result; 
} 


template <typename T> 
bool more_or_equal_n(const vector<T>& v1, const vector<T>& v2, size_t n) 
{ 

    assert(v1.size() == v2.size()) ;

    bool result = true;

    for (int i = 0; i < v1.size() && i < n; ++i) { 
        
        if (v1[i] < v2[i]) {
            result = false;
            break;
        } 
        
    } 
    
    return result; 
} 


struct Post { 
    int relevance;
    vector<int> properties;

    Post(int r, const string& props) : relevance(r) {

        properties.reserve(props.size());

        for (char c : props) {
            properties.push_back(c == '1' ? 1 : 0) ;
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

    vector<int> posts_ids(n);
    iota(posts_ids.begin(), posts_ids.end(), 0);

    partial_sort(posts_ids.begin(), posts_ids.begin() + m, posts_ids.end(), 
                [&](int lhs, int rhs) {
                    return posts[lhs].relevance > posts[rhs].relevance ;
                });

    cout << posts_ids << endl;

    unordered_set<int> top_posts;
    int top_sum_relevance = 0;
    vector<int> top_properties(k, 0);

    for (int i = 0; i < m; ++i) {

        top_posts.insert(posts_ids[i]);
        top_sum_relevance += posts[posts_ids[i]].relevance;
        top_properties = top_properties + posts[posts_ids[i]].properties;
    }


    cout << top_properties << endl;

    if (top_properties >= A) {
        cout << top_sum_relevance << endl;
        exit(0);
    }
    

    for (int i = 0; i < k; ++i) {


        if ( more_or_equal_n(top_properties, A, i+1) ) {
            continue;
        }

        
        






    }
   



    return EXIT_SUCCESS;
}