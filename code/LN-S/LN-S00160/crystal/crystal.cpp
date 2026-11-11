#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 1,M = 1e18 + 1,L = 1e9 + 5;
int n,m,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(m <= L){
        sort(a + 1,a + 1 + n);
        int _max = 1;
        for(int i = n;i >= 1;i--){
            int cnt = 1,m2 = m;
            for(int j = i - 1;m2 > 0 && j >= 1;j--){
                m2 -= (a[i] - a[j]);
                if(m2 >= 0) cnt ++;
                else break;
            }
            _max = max(cnt,_max);
        }
        cout << _max;
    }
    else{
        int x = a[2] - a[1],_sum = 1;
        for(int i = 1;i < n;i++){
            if(m <= i * x) break;
            m -= i * x;
            _sum ++;
        }
        cout << _sum;
    }
    return 0;
}
