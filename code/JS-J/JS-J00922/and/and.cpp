#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    vector<int>v(n),vis(n,1);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=31;i>=0;i--){
        int x=1<<i,cnt=0;
        for(int j=0;j<n;j++)if((v[j]&x)&&vis[j]==1)cnt++;
        if(cnt<m)continue;
        ans+=x;
        for(int j=0;j<n;j++)if(!(v[j]&x))vis[j]=0;
    }
    cout<<ans;
    return 0;
}
