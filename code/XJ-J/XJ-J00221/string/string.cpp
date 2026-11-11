#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5+10;
int n;
char c[N];
LL a[N],ans = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    int L = 1,R = n;
    while(L < R){
        if(c[L] == c[R]){
            LL nmin = min(a[L],a[R]);
            a[L] -= nmin,a[R] -= nmin;
            if(a[L] == 0)   L++;
            if(a[R] == 0)   R--;
        } else {
            LL nmin = min(a[L],a[R]);
            a[L] -= nmin,a[R] -= nmin,ans += nmin;
            if(a[L] == 0)   L++;
            if(a[R] == 0)   R--;
        }
    }
    cout << ans;
    return 0;
}