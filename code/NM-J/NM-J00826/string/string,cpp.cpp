#include<bits/stdc++.h>
using namespace std;
#define int long long;
signed main(){
    freopen(string.in,"r",stdin);
    freopen(string.out,"w",stdout);
    int l;
    cin>>l;
    int st;
    char p;
    vector<char> v8;
    for(int i=0;i<l;i++){
        cin>>st;
        cin>>p;
        for(int i=0;i<st;i++){
            v8.push_back(p);
        }
    }
    int sum=0;
    char *left=v8.begin(),*right=v8.end()+1;
    for(int i=0;i<v8.size()/2+1;i++){
        if(&left!=&right){
            sum++;
            left++;right--;
            continue;
        }
    }
    cout<<sum;
    return 0;
}
