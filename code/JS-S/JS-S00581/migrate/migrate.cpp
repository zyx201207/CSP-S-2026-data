#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T,n,d,a[N],ans,lst[N],dist[N],flag[N];
void solve(){
    cin>>n>>d;ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1,j=1;i<=n;i++){
        while(a[i]-a[j]>d) j++;
        lst[i]=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n+2;j++)
            flag[j]=dist[j]=-1;
        flag[i]=dist[i]=0;
        for(int j=i+1;j<=n;j++){
            if(lst[j]==j) break;
            int x=max(lst[j],i);dist[j]=dist[x]+1;
            if(dist[x]==dist[x+1]) flag[j]=flag[x]+1;
            else flag[j]=flag[x];
            if(dist[x]==dist[x+2]) flag[j]++;
            if(flag[j]==1) ans++;
        }
    }
    cout<<ans<<'\n';
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--)solve();
    return 0;
}