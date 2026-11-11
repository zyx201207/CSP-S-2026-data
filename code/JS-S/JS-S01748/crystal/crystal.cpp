#include <bits/stdc++.h>
using namespace std;

long long a[500001],dp[500001];
bool cmp(long long x,long long y){
    return x>y;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxn = -1;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n>=500000){
        dp[1] = 0;
        for(int i = 2;i <= n;i++){
            dp[i] = dp[i-1]+a[1]-a[i];
            if(m<dp[i]){
                cout << i-1;
                return 0;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        long long cnt = 0,mx = m;
        for(int j = i;j <= n;j++){
            if(a[i]-a[j] <= mx){
                mx = mx-a[i]+a[j];
                cnt++;
            }
        }
        maxn = max(maxn,cnt);
    }
    cout << maxn;
    return 0;
}
