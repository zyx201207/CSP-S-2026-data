#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200010];
    unsigned long long ans = 0;
    char s[200010];
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cin >> s[i];
    }
    int l = 1;
    int r = n+1;
    while(l<r){
        if(s[l] == s[r]){
            if(a[l] >= a[r]){
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }
            else{
                a[r] -= a[l];
                a[l] = 0;
                l++;
            }
        }
        else{
            if(a[l] >= a[r]){
                a[l] -= a[r];
                ans += a[r];
                a[r] = 0;
                r--;
            }
            else{
                a[r] -= a[l];
                ans += a[l];
                a[l] = 0;
                l++;
            }
        }
    }
    cout << ans;
    return 0;
}
