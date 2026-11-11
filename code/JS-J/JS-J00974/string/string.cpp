#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;
int a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long cnt = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    int l1 = 1;
    int l2 = n;
    long long ans = 0;
    while (l1 < l2){
        if (a[l1] < a[l2]){
            if (c[l1] != c[l2]){
                ans += 1ll * a[l1];
            }
            a[l2] -= a[l1];
            l1++;
        }
        else if (a[l1] == a[l2]){
            if (c[l1] != c[l2]){
                ans += 1ll * a[l1];
            }
            l1++;
            l2--;
        }
        else{
            if (c[l1] != c[l2]){
                ans += 1ll * a[l2];
            }
            a[l1] -= a[l2];
            l2--;
        }
    }
    cout << ans;
    return 0;
}
