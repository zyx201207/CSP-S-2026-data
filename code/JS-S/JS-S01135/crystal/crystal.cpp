#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
__int128 dif[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        dif[i] = a[i] - a[i - 1];
    }
    long long mx = -1e9;
    __int128 sum = 0;
    long long start = 1;
    for(int i = 2;i <= n;i++){
        sum += dif[i] * (i - start);
        if(sum > m){
            mx = max(mx,i - start);
            sum -= a[i] - a[start];
            start++;
        }
    }
    if(mx == -1e9){
        mx = n;
    }
    cout << mx << endl;
    return 0;
}
