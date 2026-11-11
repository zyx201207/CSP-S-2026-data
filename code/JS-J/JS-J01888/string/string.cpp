#include <bits/stdc++.h>
using namespace std;
typedef int re;typedef long long ll;
ll n,ans,num[200005];
char c[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (re i = 1;i <= n;i++) cin >> num[i] >> c[i];
    ll l = 1,r = n;
    while (l < r){
        if (c[l] == c[r]){
            if (num[l] > num[r]){
                num[l] -= num[r];
                num[r] = 0;
                r--;
            }
            else if (num[l] < num[r]){
                num[r] -= num[l];
                num[l] = 0;
                l++;
            }
            else if (num[l] == num[r]){
                num[l] = 0;
                num[r] = 0;
                l++;r--;
            }
        }
        else if (c[l] != c[r]){
            if (num[l] > num[r]){
                ans += num[r];
                num[l] -= num[r];
                num[r] = 0;
                r--;
            }
            else if (num[l] < num[r]){
                ans += num[l];
                num[r] -= num[l];
                num[l] = 0;
                l++;
            }
            else if (num[l] == num[r]){
                ans += num[l];
                num[l] = 0;
                num[r] = 0;
                l++;r--;
            }
        }
    }cout << ans;
    return 0;
}
