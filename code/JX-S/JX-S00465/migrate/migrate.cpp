#include <bits/stdc++.h>
using namespace std;

int c,t;
int n;
long long d;
int N[2000050];
int dp[2005000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>N[i];
        }
        for (int k=2+d;k<=n-2-d;k++){
            if ((N[k]-N[1])>=((d+1)/2)){
                dp[k] = dp[k-1] + 1;
            }
        }
        long long ans = 0,k1=1;
        for (int i=1;i<=n;i++){
            ans += k1*dp[i];
            k1++;
        }
        cout<<0<<endl;
    }
    return 0;
}
