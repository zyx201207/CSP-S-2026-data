#include <bits/stdc++.h>
using namespace std;
long long t, ans;
int n[100010];
char a[100010];
long long tmp;
long long l, r;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n[i] >> a[i];
        tmp += n[i];
    }
    for(int i = 1; i <= t / 2; i++){
        if(n[t-i+1] < n[i] && a[i] != a[t-i+1]){
            ans += n[t-i+1];
            l += n[t-i+1];
            r += n[t-i+1];
        }
        else if(n[t-i+1] >= n[i] && a[i] != a[t-i+1]){
            ans += n[i];
            l += n[i];
            r += n[i];
        }
    }
    if(l + r < tmp){
        if((tmp - (l + r)) % 2 == 0){
            ans += (tmp - (l + r)) / 2;
        }else{
            ans += tmp - (l + r);
        }
    }
    cout << ans;
    return 0;
}
