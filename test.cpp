#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);
    for(int i = 0; i < v.size(); i++) {
        if(i == 5)
            v.erase(v.begin() + i);
        cout << v[i] << endl;
    }
    cout << "size: " << v.size() << endl;
    return 0;
}