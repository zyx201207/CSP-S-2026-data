#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
char c[200005];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    long long cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        cnt += a[i];
    }
    long long i = 1, j = n, x = a[1], y = a[n], ans = 0;
    while(i < j){
        if(x > y){
            if(c[i] != c[j]){
                ans += y;
            }
            x -= y;
            y = 0;
            j--;
            y = a[j];
        }else{
            if(c[i] != c[j]){
                ans += x;
            }
            y -= x;
            x = 0;
            i++;
            x = a[i];
        }
    }
    cout << ans;
    return 0;
}
