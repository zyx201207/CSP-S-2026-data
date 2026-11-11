#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5,M=3e5+5;
int del[N],n,m,a[N],last[M],ans[M];
bool spA=1;
int f(int x){
    return (del[x]?(del[x]=f(del[x])):x);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) spA=0;
        if(last[a[i]]) del[last[a[i]]]=i;
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++) f(i);
    //int delto=0;
    //for(int i=n;i>=1;i--){
    //    if(del[i])
    //}
    if(m==1){
        cout<<n;
        return 0;
    }
    if(spA){
        for(int i=1;i<=n;i++){
            while(del[i]) i=del[i];
            ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int pos=i;pos<=n;pos++){
            while(del[pos]) pos=del[pos];
            ans[a[pos]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
