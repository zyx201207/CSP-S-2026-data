#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int O=30;
inline int read(){
    int f=0,num=0,c=cin.rdbuf()->sbumpc();
    while(!isdigit(c)){
        if(c=='-')f=1;
        c=cin.rdbuf()->sbumpc();
    }
    while(isdigit(c)){
        num=(num<<1)+(num<<3)+(c^48);
        c=cin.rdbuf()->sbumpc();
    }
    return f?-num:num;
}


signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n=read(),m=read();
    vector<int>a(n);
    for(int i=0;i<n;++i){
        a[i]=read();
    }
    int ans=0;
    for(int o=O;o>=0;--o){
        int cc=0;
        vector<int>na;
        for(int v:a){
            if(v>>o&1){
                ++cc;
            }
        }
        if(cc>=m){
            ans|=1ll<<o;
            na.reserve(n);
            for(int v:a){
                if(v>>o&1){
                    na.emplace_back(v);
                }
            }
            swap(a,na);
        }
    }
    cout<<ans;
    
    return 0;
}