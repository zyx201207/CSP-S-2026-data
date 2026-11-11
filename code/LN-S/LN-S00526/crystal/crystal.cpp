#include<bits/stdc++.h>
using namespace std;
# define int long long
int n,m,ans;
int a[500005];
int b[500005];
void work(){
    int k = a[n/2+1];
    for(int i=1;i<=n;i++) b[i] = abs(a[i]-k);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        if(m>=b[i]){
            m -= b[i];
            ans++;
        }
        else break;
    }
    return;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(n%2){
        work();
        cout << ans;
    }
    else{
        int u = m;
        int k = a[n/2+1];
        work();
        int ans1 = ans;
        ans = 0;
        k = a[n/2];
        for(int i=1;i<=n;i++) b[i] = abs(a[i]-k);
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++){
            if(u>=b[i]){
                u -= b[i];
                ans++;
            }
            else break;
        }
        cout << max(ans1,ans);
    }
    return 0;
}
