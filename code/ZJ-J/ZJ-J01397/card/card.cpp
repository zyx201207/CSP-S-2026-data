#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int cnt[300005];
int lst[300005];
int d[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        lst[a[i]]=i;
        d[i]=1;
    }
    for (int i=1;i<=n;i++){
        cnt[a[i]]+=d[i];
        d[lst[a[i]]+1]+=d[i];
    }
    for (int i=1;i<=m;i++){
        cout<<cnt[i];
        if (i!=m)cout<<" ";
    }
    cout<<endl;
    return 0;
}