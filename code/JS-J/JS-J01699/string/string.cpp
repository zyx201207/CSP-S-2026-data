#include <bits/stdc++.h>
using namespace std;

long long l[100001] , pos = 0 , r[100001] , cnt = 0;
char s[100001] , y;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n , x;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> x >> y;
        if(y == s[pos]){
            r[pos] += x;
        }else{
            pos ++;
            l[pos] = r[pos - 1] + 1;
            r[pos] = l[pos] + x - 1;
            s[pos] = y;
        }
    }
    long long mid = ((r[pos] & 1 ? r[pos] + 1 : r[pos]) >> 1);
    long long m = lower_bound(r + 1 , r + pos + 1 , mid) - r;
    for(int i = 1 ; i <= m ; i ++){
        long long p1 = r[pos] + 1 - (mid < r[i] ? mid : r[i]) , p2 = r[pos] + 1 - l[i] , e = 0 , v = 0;
        long long j1 = lower_bound(r + 1 , r + pos + 1 , p1) - r , j2 = lower_bound(r + 1 , r + pos + 1 , p2) - r;
        for(int j = j1 ; j <= j2 ; j ++){
            if(s[j] == s[i]) continue;
            if(l[j] < p1){
                e = p1;
            }else{
                e = l[j];
            }
            if(r[j] > p2){
                v = p2;
            }else{
                v = r[j];
            }
            cnt += v - e + 1;
        }
    }
    cout << cnt;
    return 0;
}
