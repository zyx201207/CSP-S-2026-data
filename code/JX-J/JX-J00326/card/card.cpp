#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],l[M],s[M],c[M],d;
vector<int> v[M];
int tg(int x,int now){
    if(now>n) return now;
    v[d].push_back(x);
    if(l[x]==now) return now;
    return tg(a[l[x]+1],l[x]+1);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]]=i;
        c[a[i]]++;
    }for(int i=1;i<=m;i++){
        d=i;
        for(int j=l[i];j<=n;j++){
            if(l[a[j]]!=j){
                int now=tg(a[j],j);
                j=now;
            }else v[d].push_back(a[j]); 
        }
    }for(int i=1;i<=m;i++){
        for(auto j:v[i]) s[j]+=c[i];
    }for(int i=1;i<=m;i++) cout<<s[i]<<" ";
    return 0;
}