#include <bits/stdc++.h>
using namespace std;
long long num[200010];
long long s[200010];
char a[200010];
int n;
int ptl,ptr;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int f = 1;
    for (int i = 1;i <= n;i++){
        cin >> num[i] >> a[i];
    }
    ptl = 1;
    ptr = n;
    while (ptl != ptr){
        if (a[ptl] != a[ptr]){
            int cache = min(num[ptl],num[ptr]);
            if (cache == num[ptl]){
                ans += cache;
                num[ptr] -= cache;
                ptl++;
            }else if (cache == num[ptr]){
                ans += cache;
                num[ptl] -= cache;
                ptr--;
            }
        }else {
            int cache = min(num[ptr],num[ptl]);
            if (cache == num[ptl]){
                num[ptr] -= cache;
                ptl++;
            }else {
                num[ptl] -= cache;
                ptr--;
            }
        }
    }
    cout << ans;
    return 0;
}
