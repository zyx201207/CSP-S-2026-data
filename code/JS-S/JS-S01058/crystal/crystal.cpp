#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500003], b[500003], ans;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)scanf("%lld", &b[i]);
    sort(b + 1, b + 1 + n);
    for(int i = 1;i < n;i++)a[i] = b[i + 1] - b[i];
    int i = 1, j = 0, cnt = 0, sum = 0, cur = 0;
    while(i < n && j < n){
        if(j < n){
            j++, cnt++;
            cur += a[j] * cnt;
            sum += a[j];
        }
        if(cur > m){
            cur -= sum;
            sum -= a[i];
            cnt--;
            i++;
        }else{
            ans = max(ans, j - i + 2);
            if(j == n - 1)break;
        }
    }
    printf("%lld", ans);
}
