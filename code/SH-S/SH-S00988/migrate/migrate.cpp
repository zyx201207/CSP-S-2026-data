#include <bits/stdc++.h>
using namespace std;
#define N 2000007
#define int long long
#define INF 0x3f3f3f3f3f3f3f3fll
int n,x[N],m;
int dp[N];//len
int cnt[N];//count
int sum[N];//qjh of cnt
int c;
void solveBF(){
    for(int i=0;i<=n;++i){
        dp[i]=cnt[i]=sum[i]=0;
    }
    int res=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            dp[j]=INF;
            cnt[i]=sum[i]=0;
        }
        dp[i]=0;
        cnt[i]=sum[i]=1;
        sum[i-1]=0;
        cnt[i-1]=0;
        int lst1=i,lst2=i;
        // available, dp =
        for(int j=i+1;j<=n;++j){
            while(lst1<j&&x[j]-x[lst1]>m){
                ++lst1;
            }
            if(x[j]-x[lst1]>m) continue;
            lst2=max(lst1,lst2);
            while(lst2<n&&dp[lst2+1]==dp[lst1]){
                ++lst2;
            }
            dp[j]=dp[lst2]+1;
            cnt[j]=sum[lst2]-sum[lst1-1];
            sum[j]=sum[j-1]+cnt[j];
            if(cnt[j]==2){
                ++res;
                //cout<<i<<' '<<j<<'\n';
            }
            // if(cnt[j]==0){
            //     break;
            // }
        }
    }
    cout<<res<<'\n';
}

void solveA(){
    int dx=x[2]-x[1];
    int cc=m/dx;
    int l=cc*2;
    cout<<max(0ll,(n-l+1))<<'\n';
}

int nxt[N];

void solvee(){
    for(int i=0;i<=n;++i){
        dp[i]=cnt[i]=sum[i]=0;
    }
    int res=0;
    int nxtt=1;
    for(int i=1;i<=n;++i){
        while(x[nxtt+1]-x[i]<=m){
            ++nxtt;
        }
        nxt[i]=nxtt;
    }
    int j=1;//fir
    int k=1;//lst
    int i=1;
        dp[i]=0;
        cnt[i]=sum[i]=1;
        sum[i-1]=0;
        cnt[i-1]=0;
        int lst1=i,lst2=i;
        for(int j=i+1;j<=n;++j){
            while(lst1<j&&x[j]-x[lst1]>m){
                ++lst1;
            }
            if(x[j]-x[lst1]>m) continue;
            lst2=max(lst1,lst2);
            while(lst2<n&&dp[lst2+1]==dp[lst1]){
                ++lst2;
            }
            dp[j]=dp[lst2]+1;
            cnt[j]=sum[lst2]-sum[lst1-1];
            sum[j]=sum[j-1]+cnt[j];
            if(cnt[j]==2){
                ++res;
                //cout<<i<<' '<<j<<'\n';
            }
            // if(cnt[j]==0){
            //     break;
            // }
        }
    cout<<res<<'\n';
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>x[i];
    }
    if(c<=10){
        solveBF();
    }
    else if(c<=12){
        solveA();
    }
    else{
        solvee();
    }
}


signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    cin>>c>>T;
    while(T--){
        solve();
    }
}