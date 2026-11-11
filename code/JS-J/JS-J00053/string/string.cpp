#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000001];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    char c[1000001];
    int cnt = 1, sum = 0;
    char s[1000001];
    for(int i = 1; i<=n; i++){
        cin >> a[i] >> c[i];
        sum+=a[i];
        while(cnt<=sum){
            s[cnt] = c[i];
            cnt++;
        }
    }
    cnt--;
    int l = 1, r = cnt, ans = 0;
    while(l<=r){
        if(s[l] != s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}