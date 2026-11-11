#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],pos[300010],cnt[300010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i;i--){
        for(int j=i;j<=n;j++){
            cnt[a[j]]++;
            if(pos[a[j]]>j)j=pos[a[j]];
            else pos[a[j]]=j;
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
