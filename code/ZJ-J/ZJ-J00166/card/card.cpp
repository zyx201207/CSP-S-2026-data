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
vector<int>fa;
int fr(int x){
    return x==fa[x]?x:fa[x]=fr(fa[x]);
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n=read(),m=read();
    vector<int>a(n+1),nxt(n+1);
    fa.assign(n+10,0);
    iota(fa.begin(),fa.end(),0);
    unordered_map<int,int>lst;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    for(int i=n;i>=1;--i){
        if(lst.count(a[i])){
            nxt[i]=lst[a[i]]+1;
        }
        else{
            nxt[i]=i+1;
            lst[a[i]]=i;
        }
    }
    vector<int>res(m+1);
    vector<int>lei(n+10);
    for(int i=1;i<=n;++i){
        // vector<int>st;
        // unordered_set<int>hv;
        lei[i]++;
        lei[nxt[i]]+=lei[i];
        res[a[i]]+=lei[i];
        // for(int j=i;j<=n;j=nxt[j]){
        //     st.emplace_back(a[j]);
        // }
        // for(int v:st){
        //     ++res[v];
        // }
    }
    for(int i=1;i<=m;++i){
        cout<<res[i]<<" ";
    }
    return 0;
}