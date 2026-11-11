#include<bits/stdc++.h>
using namespace std;

int a[200005];
char c[200005];

int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i] >> c[i];
    }
    long long l = 1 , r = n , cntl = a[1] , cntr = a[n] , cntmin = 0 , ans = 0;
    while(l <= r){
        if(c[l] != c[r]){
            ans += (min(cntl , cntr) - cntmin);
        }
        cntmin = min(cntl , cntr);
        if(cntl < cntr){
            l ++;
            cntl += a[l];
        }
        else{
            r --;
            cntr += a[r];
        }
    }
    cout << ans;
    return 0;
}
