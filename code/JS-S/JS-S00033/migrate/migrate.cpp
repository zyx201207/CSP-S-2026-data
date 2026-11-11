#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int f[N], dp[5005][5005];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin>>c>>t;
    while(t--){
        int n, d, ans=0, cha=0;
        cin>>n>>d;
        for(int i=1; i<=n; i++) {cin>>f[i];cha=f[i]-f[i-1];}

        for(int i=1; i<n; i++){
            int t=f[i], num=1, j=i+1, cnt=0;
            while(j<=n){
                while(j<=n&&f[j]-t<=d){
                    dp[i][j]=num;
                    j++;
                    cnt++;
                }
                if(cnt==1) ans++;
                t=f[j-1];
                j++;
                num++;
                cnt=0;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
