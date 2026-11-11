#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a[200010];
    char c[200010];
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    long long ans = 0,r1 = 0;
    int r2;
    for(int i = 1;i <= (n+1)/2;i++){
        if(r1 != 0){
            if(r2 == i-1){
                a[n-i+1] -= r1;
                if(c[r2] != c[n-i+1]) ans += r1;
                if(a[n-i+1] < 0){
                    r1 -= a[n-i+1]+r1;
                    r2++;
                    continue;
                }
            }else{
                a[i] -= r1;
                if(c[r2] != c[i]) ans += r1;
                if(a[i] < 0){
                    r1 -= a[i]+r1;
                    r2++;
                    continue;
                }
            }
        }
        if(c[i] != c[n-i+1]){
            ans += min(a[i],a[n-i+1]);
        }
        if(a[i] >= a[n-i+1]){
            r1 = a[i] - a[n-i+1];
            r2 = i;
        }else{
            r1 = a[n-i+1] - a[i];
            r2 = n-i+1;
        }
    }
    cout << ans;
}
