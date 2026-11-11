#include<bits/stdc++.h>
using namespace std;
#define int long long 

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
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n=read();
    vector<pair<int,char>>a(n+1);
    int L=0;
    vector<int>pre(n+1);
    for(int i=1;i<=n;++i){
        a[i].first=read();
        pre[i]=pre[i-1]+a[i].first;
        cin>>a[i].second;
        L+=a[i].first;
    }
    auto b=a;
    reverse(b.begin()+1,b.end());
    int ans=L;
    int i=1,j=1;
    while(i<=n&&j<=n){
        int d=min(a[i].first,b[j].first);
        // cerr<<"i="<<i<<" "<<a[i].first<<" "<<a[i].second<<"\n";
        // cerr<<"j="<<j<<" "<<b[j].first<<" "<<b[j].second<<"\n";
        if(a[i].second==b[j].second){
            ans-=d;
        }
        a[i].first-=d,
        b[j].first-=d;
        if(a[i].first==0){
            ++i;
        }
        if(b[j].first==0){
            ++j;
        }
    }
    cout<<ans/2;
    
    return 0;
}