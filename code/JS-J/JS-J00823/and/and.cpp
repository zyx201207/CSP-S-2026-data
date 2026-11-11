#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[114514*2],vis[114514*2];
main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int c=0,ans=0;
    for(int i=31;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++)if(((a[j]>>i)&1))cnt++;
        if(cnt<m)continue;
        for(int j=1;j<=n;j++)if(((a[j]>>i)&1))vis[j]++;
        c++;
        int res=0;
        for(int j=1;j<=n;j++)res+=(vis[j]==c);
        if(res>=m)ans+=(1<<i);
    }
    cout<<ans;
}
