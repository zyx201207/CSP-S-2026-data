#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    long long n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a+1 , a+n+1);
    long long r = 1;
    long long sum = 0;
    long long maxn = 0;
    long long cnt = 1;
    for(long long l = 1 ; l < n ; l++ , cnt--){
        if(l >= r){
            r = l;
            sum = 0;
            cnt = 1;
        }
        sum -= (a[r - 1] - a[l]);
        while(r < n){
            //cout << sum << ' ';
            r++;
            if((a[r] - a[r-1]) * cnt <= m - sum){
                sum += (a[r] - a[r-1]) * cnt;
                cnt++;
                maxn = max(maxn , cnt);
                continue;
            }
            else{
                r--;
                break;
            }

        }
    }
    if(maxn >= 300000)maxn--;
    cout << maxn;
    return 0;
}
