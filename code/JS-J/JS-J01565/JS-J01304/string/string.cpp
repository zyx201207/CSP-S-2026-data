#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N],n;
char c[N];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i] >> c[i];
    }
    long long l = 1,r = n,ans = 0,suml = a[1],sumr = a[n];
    while(l < r) {
        if(suml > sumr){
            suml -= sumr;
            ans += (c[l] != c[r]) * sumr;
            r --;
            sumr = a[r];
        }else if(suml == sumr) {
            ans += (c[l] != c[r]) * sumr;
            r --;
            l ++;
            suml = a[l];
            sumr = a[r];
        } else {
            sumr -= suml;
            ans += (c[l] != c[r]) * suml;
            l ++;
            suml = a[l];
        }
    }
    cout << ans;
    return 0;
}
