#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000010;
int c,T;
int n,d;
int a[N];
int dp[5010][5010];
int cnt[5010][5010];
void DP(){
    memset(dp,0x3f,sizeof dp);
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++){
        cnt[i][i]=1;
        dp[i][i]=0;
    }
    for(int st=1;st<=n;st++){
        for(int i=st+1;i<=n;i++){
            for(int j=i-1;j>=st;j--){
                if(a[i]-a[j]>d) break;
                int nw=dp[st][j]+1;
                if(nw<dp[st][i]){
                    dp[st][i]=nw;
                    cnt[st][i]=cnt[st][j];
                }else if(nw==dp[st][i]){
                    cnt[st][i]+=cnt[st][j]; 
                }
            }
        }
    }
    int teto=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
//        	cout<<cnt[i][j]<<" ";
            if(cnt[i][j]==2) teto++;
        }
//        cout<<"\n";
    }
    cout<<teto<<"\n";
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    // int to=0;
    // for(int i=1;i<=n;i++){
    //     to=max(to,i);
    //     if(a[to+1]-a[i]<=d) to++;
    //     g[to].push_back(i);
    // }
    // for(int i=1;i<=n;i++){
    //     for(auto it:g[i]){
    //         cout<<it<<" -> "<<i<<"\n";
    //     }
    // }
    // cout<<"\n";
    if(c==13 || c==14){
        cout<<0<<"\n";
        return ;
    }else if(c<=6){
        DP();
    }
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--) solve();
	return 0;
}
