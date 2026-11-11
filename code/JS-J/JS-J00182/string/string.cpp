#include <bits/stdc++.h>
using namespace std;
int n , a[200001];
char c[200001];
long long solve(int l , int r){
    if (a[l] == 0) l++;
    if (a[r] == 0) r--;
    if (l >= r) return 0;
    int sum = 0 , x = min(a[l] , a[r]);
    a[l] -= x , a[r] -= x , sum += x;
    return (c[l] == c[r] ? 0 : sum) + solve(l , r);
}
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cout.tie(0) , cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] >> c[i];
    cout << solve(1 , n);
    return 0;
}
