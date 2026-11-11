#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
const int M=2e6+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,t;
ll n,d;
ll a[M],dp[N][N],cnt[N][N],dp1[M];
void solve1(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=INF;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            if(a[i]-a[j]<=d){
                dp[i][j]=1;
                cnt[i][j]=1;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){
            for(int j=k+1;j<=n;j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    cnt[i][j]=1;
                }else if(dp[i][j]==dp[i][k]+dp[k][j]){
                    cnt[i][j]++;
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(cnt[i][j]==2)
                ans++;
    cout<<ans<<'\n';
}
void solve2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[2]-a[1]>d){
        cout<<0<<'\n';
        return ;
    }
    int dis=a[2]-a[1];
    int num=d/dis;
    cout<<(n-1)/num<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12)
        while(t--)solve2();
    else
        while(t--)
            solve1();
    return 0;
}
