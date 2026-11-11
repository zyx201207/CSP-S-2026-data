#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long a[n+1];
    char b[n+1];
    long long ans = 0;
    int l = 1;
    int r = n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cin >> b[i];
    }
    while(1){
        if(r <= l){
            break;
        }
        if(a[l] == a[r] && b[l] == b[r]){
            l++;
            r--;
            continue;
        }
        if(b[l] == b[r]){
            if(a[l] > a[r]){
                a[l] = a[l] - a[r];
                r--;
            }else{
                a[r] = a[r] - a[l];
                l++;
            }
            continue;
        }
        if(a[l] == a[r]){
            ans = ans + a[l];
            l++;
            r--;
            continue;
        }
        if(a[l] > a[r]){
            ans += a[r];
            b[r] = b[l];
        }else{
            ans += a[l];
            b[l] = b[r];
        }
    }
    cout << ans;
    return 0;
}
