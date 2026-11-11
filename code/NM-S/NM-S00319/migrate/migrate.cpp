#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,n,d,a[N],r[N],ans,dist[N],f[N];
void solve(){
    cin>>n>>d;
    ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        r[i]=r[i-1];
        while(r[i]<n && a[r[i]+1]-a[i]<=d) ++r[i];
    }
    if(c==11 || c==12){
        for(int i=1;i<=n;i++) dist[i]=0,f[i]=1;
        for(int i=n-1;i;i--){
            if(r[i]==i) break;
            dist[i]=dist[r[i]]+1;
            f[i]=f[r[i]];
            if(r[i]-1>i && r[i]-1<n && dist[r[i]-1]==dist[r[i]]) f[i]+=f[r[i]-1];
            if(r[i]-2>i && r[i]-2<n && dist[r[i]-2]==dist[r[i]]) f[i]+=f[r[i]-2];
            f[i]=min(f[i],3ll);
            if(f[i]==2) ans+=i;
        }
        cout<<ans<<"\n";
        return ;
    }
    for(int i=n;i>1;i--){
        for(int j=1;j<=n;j++) dist[j]=0,f[j]=1;
        for(int j=i-1;j;j--){
            if(r[j]==j) break;
            dist[j]=dist[r[j]]+1;
            f[j]=f[r[j]];
            if(r[j]-1>j && r[j]-1<i && dist[r[j]-1]==dist[r[j]]) f[j]+=f[r[j]-1];
            if(r[j]-2>j && r[j]-2<i && dist[r[j]-2]==dist[r[j]]) f[j]+=f[r[j]-2];
            f[j]=min(f[j],3ll);
            if(f[j]==2) ++ans;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _;
    cin>>c>>_;
    while(_--) solve();
    return 0;
}
