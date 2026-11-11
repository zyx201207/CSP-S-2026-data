#include <bits/stdc++.h>
using namespace std;
int a[500005],t[300005],cnt[300005],ls[500005],n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        ls[t[a[i]]+1]+=++ls[i];
        cnt[a[i]]+=ls[i];
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
