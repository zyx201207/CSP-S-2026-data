#include<bits/stdc++.h>
using namespace std;
int a[200007];
char b[200007];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    int l = 1, r = n;
    long long ans = 0;
    while(l < r){
        if(a[l] > a[r]){
            if(b[l] != b[r]){
                ans += (1LL*a[r]);
            }
            a[l] -= a[r];
            r--;
        }else{
            if(b[l] != b[r]){
                ans += (1LL*a[l]);
            }
            a[r] -= a[l];
            l++;
        }
    }
    cout << ans;
    return 0;
}
