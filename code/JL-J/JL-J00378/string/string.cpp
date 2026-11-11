#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n, ans;
    cin >> n;
    char b[n+5] = {};
    int a[n+1] = {};
    for(int i = 1; i <= n+1; i++){
        cin >> a[i] >> b[i];
    }
    if(a[1] != a[n+1]&&a[1] > a[n+1]){
        a[n+1] = a[n+1] + (a[1] - a[n+1]);
        ans += a[1] - a[n+1];
    }
    if(a[1] != a[n+1]&&a[1] < a[n+1]){
        a[1] = a[1] + (a[n+1] - a[1]);
        ans += a[n+1] - a[1];
    }
    if(b[1] != b[n+1]&&b[1] > b[n+1]){
        b[n+1] = b[n+1] + (b[1] - b[n+1]);
        ans += b[1] - b[n+1];
    }
    if(b[1] != b[n+1]&&b[1] < b[n+1]){
        b[1] = b[1] + (b[n+1] - b[1]);
        ans += b[n+1] - b[1];
    }
    cout << ans;
    return 0;
}
