#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2 * 1919810;
int c,t;
int n,d;
int a[N],f1[N],f2[N],l[N],r[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        int ans = 0;
        for(int i = 1;i <= n;i ++ ){
            f1[i]=0,f2[i] = 0;
            cin >> a[i];
        }
        a[0] = LONG_LONG_MIN;f2[0]=f1[0]= 0;
        a[n + 1] = LONG_LONG_MAX;f2[n+1]=f1[n+1]=0;
        for(int i = 1;i <= n;i ++ ){
            int t1 = lower_bound(a,a + n + 2,a[i] - d) - a;
            l[i] = i - t1;
            int t2 = upper_bound(a,a + n + 2,a[i] + d) - a;
            r[i] = t2 - i - 1;
        }
        if(c==11||c==12){
            if(n <= 3) cout << 0 << endl;
            else{
                if(r[1] != 2) cout << 0 << endl;
                else{
                    cout << n - 3 << endl;
                }
            }
            continue;
        }
        for(int i = 1;i + 3 <= n;i ++ ){
            if(r[i] == 2 && l[i + 3] == 2){
                int sum1 = 1;
                for(int j = i - 1;j >= 1;j -- ){
                    if(r[j] < i - j) sum1++;
                    else break;
                }
                int sum2 = 1;
                for(int j = i + 1;j <= n;j ++ ){
                    if(l[j] < j - i) sum2++;
                    else break;
                }
                ans += sum1 * sum2;
            }
            // f1[i] += f1[i - l[i]];
        }
        cout << ans << endl;
    }
}