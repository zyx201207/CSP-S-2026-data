#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2*(int)1e6+5],dp[2*(int)1e6+5],s[2*(int)1e6+5],p[2*(int)1e6+5],ss[2*(int)1e6+5];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i<=n;i++){
            cin >> a[i];
        }
        for(int i = 1;i<=n;i++){
            for(int j = i;j>=1;j--){
                if(a[i]-a[j]<=d) s[i]=j;
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = i;j<=n;j++) p[j]=ss[j]=dp[j]=0;
            for(int j = i+1;j<=n;j++){
                if(a[j]-a[i]<=d) dp[j]=p[j]=1;
            }
            for(int j = i+1;j<=n;j++){
                ss[j]=ss[j-1]+dp[j];
            }
            for(int j = i+1;j<=n;j++){
                if(!dp[j]){
                    int l = max(s[j],i+1);
                    int r = j-1;
                    p[j] = p[l]+1;
                    int R = l;
                    while(l<=r){
                        int mid=l+r>>1;
                        if(p[mid]+1!=p[j]){
                            r = mid-1;
                        }
                        else{
                            l = mid+1;
                            R = mid;
                        }
                    }
                    dp[j] = ss[R]-ss[max(s[j],i+1)-1];
                    ss[j]=ss[j-1]+dp[j];
                    ans+=(dp[j]==2);
                }
            }
        }
        cout << ans << '\n';

    }
    return 0;
}
