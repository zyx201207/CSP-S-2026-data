#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e6+5;

int c,t;
ll n,d,x[N];
struct islands{
    ll paths;
    vector<ll>from;
}dp[N];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            dp[i].paths=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;x[j]-x[i]<=d&&j<=n;j++){
                if(dp[j].paths==0){
                    dp[j].paths=dp[i].paths+1ll;
                    dp[j].from.push_back(i);
                    cout<<0<<' '<<dp[j].paths<<'\n';
                }else if(dp[i].paths+1ll<dp[j].paths){
                    dp[j].paths=dp[i].paths+1ll;
                    dp[j].from.clear();
                    dp[j].from.push_back(i);
                    cout<<1<<' '<<dp[j].paths<<'\n';
                }else if(dp[j].paths==dp[i].paths+1ll){
                    dp[j].from.push_back(i);
                    cout<<2<<' '<<dp[j].paths<<'\n';
                }
            }
        }


    }


    return 0;
}
