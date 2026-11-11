#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[200050], b[200050];
ll len, ans;
char c1[200050], c2[200050];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c1[i];
        b[n - i + 1] = a[i], c2[n - i + 1] = c1[i];
    }
    for(int i = 1, j = 1; i <= n && j <= n;){
        if(c1[i] != c2[j]){
            ans += min(a[i], b[j]);
        }
        if(a[i] > b[j]){
            a[i] -= b[j];
            j++;
        }
        else if(a[i] < b[j]){
            b[j] -= a[i];
            i++;
        }
        else{
            i++, j++;
        }
    }
    cout << ans / 2;

    return 0;
}
