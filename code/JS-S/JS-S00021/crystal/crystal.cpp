#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500001] , m;
bool f(long long x){
    long long sum = 0;
    for (int i = 1 ; i <= n ; i++)
        if (a[i] < x) sum += x - a[i];
    return sum <= m;
}
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    scanf("%d%lld" , &n , &m);
    for (int i = 1 ; i <= n ; i++)
        scanf("%lld" , &a[i]);
    long long l = -1e12 , r = 1e12;
    while (l < r){
        long long mid = (l + r + 1) >> 1;
        if (f(mid)) l = mid;
        else r = mid - 1;
    }
    int num = 0;
    for (int i = 1 ; i <= n ; i++)
        if (a[i] <= l) num++;
    cout << num;
    return 0;
}
