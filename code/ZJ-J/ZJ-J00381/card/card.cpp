#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,m,a[N],fa[N];
ll w[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)w[i]=1;
    map<int,int>mp;
    for(int i=n;i>=1;i--){
        if(!mp.count(a[i])){
            mp[a[i]]=i;
        }
        int u=mp[a[i]];
        fa[i]=u+1;
    }
    for(int i=1;i<=n;i++){
        if(fa[i]<=n){
            w[fa[i]]+=w[i];
        }
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]+=w[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i];
        if(i<m)cout<<" ";
    }
    cout<<"\n";
    return 0;
}