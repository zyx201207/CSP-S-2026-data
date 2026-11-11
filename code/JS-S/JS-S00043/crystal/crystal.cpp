#include <bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c.begin(),c.end());
    auto check=[&](int x)->bool{
        if(x==0) return true;
        if(c.size()<x) return false;
        int val=c[x-1];
        int ans=0;
        for(int i=0;i<x;i++){
            int add=val-c[i];
            ans+=add;
        }
        if(ans>m) return false;
        return true;
    };
    int l=0,r=500002;
    while(l<r){
        int mid=l+((r-l)/2)+1;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<l<<endl;
    #undef int
    return 0;
}
// ________  ________
//|  ____  ||  ____  |   __      __    __
//| |____| || |____| | _|  |_  _|  |_ |__|
//|  ____  ||  ______||_    _||_    _| __
//|_|    \_\|_|         |__|    |__|  |_/
//    R         P        +       +     ;