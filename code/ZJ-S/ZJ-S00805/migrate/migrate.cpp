#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2000010;
const i64 INF=0x3f3f3f3f3f3f3f3fll;
i64 n,d;
i64 x[N];
int to[N];
i64 dis[N],dp[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=n,j=n;i>=1;i--){
        while(j>i&&x[j]-x[i]>d)j--;
        to[i]=j;
    }
    bool flag=true;
    for(int i=2;i<=n;i++){
        if(x[i]-x[i-1]!=x[2]-x[1]){
            flag=false;
            break;
        }
    }
    if(n>5000&&flag){
        if(d<2*(x[2]-x[1]))cout<<"0\n";
        else cout<<max(0ll,n-2*d/(x[2]-x[1])+1)<<"\n";
        return;
    }
    else if(n>5000){
        i64 ans=0;
        for(int i=1;i<=n;i++){
            if(to[i]<=i+1)continue;
            int L=to[to[i]-1];
            int LL=to[to[i]-2];
            ans+=L-LL;
        }
        cout<<ans<<"\n";
        return;
    }
    i64 ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)dis[j]=INF;
        dis[i]=0,dp[i]=1;
        for(int j=i;j<n;j++)dis[to[j]]=min(dis[to[j]],dis[j]+1);
        for(int j=n-1;j>=i;j--)dis[j]=min(dis[j],dis[j+1]);
        for(int j=i+1,k=i;j<=n;j++){
            if(dis[j]==INF)break;
            while(k<j&&x[j]-x[k]>d)k++;
            dp[j]=dp[k];
            if(k+1<j&&dis[k+1]+1==dis[j])dp[j]+=dp[k+1];
            if(k+2<j&&dis[k+2]+1==dis[j])dp[j]+=dp[k+2];
            dp[j]=min(dp[j],3ll);
            if(dp[j]==2)ans++;
        }
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c=0,Tc=1;
    cin>>c>>Tc;
    while(Tc--)solve();
    return 0;
}
/*

*/