#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6,M = 5000;
int c,t,ans,x[N + 5],dp[M + 5],sta[M + 5];

int fnd(int val,int num){
    int l = 1,r = num;
    while(l < r){
        int mid = (l + r) >> 1;
        if(x[mid] >= val)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i = 1;i <= t;i++){
        ans = 0;
        int n,d;
        cin >> n >> d;
        for(int j = 1;j <= n;j++){
            cin >> x[j];
        }
        if(n == 1){
            ans = 0;
        }
        else if(c <= 10){
            for(int j = 1;j <= n;j++){
                dp[j] = 0,sta[j] = 1;
                for(int k = j + 1;k <= n;k++){
                    sta[k] = 0;
                    int last = max(j,fnd(x[k] - d,n));
                    if(last == k)   
                        break;
                    dp[k] = dp[last] + 1;
                    while(last < k && dp[last] == dp[k] - 1 && sta[k] <= 2){
                        sta[k] += sta[last];
                        last++;
                    }
                    if(sta[k] == 2){
                        ans++;
                    //    cout << j << " " << k << "\n";
                    }
                }
            }
        }
        else if(c == 11 || c == 12){
            int ms = d / (x[2] - x[1]);
            if(ms <= 1)
                ans = 0;
            else    
                ans = max((int)0,n - 2 * ms + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}