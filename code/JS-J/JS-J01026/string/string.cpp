#include<bits/stdc++.h>
using namespace std;
int n, a[200005];
long long ans;
char c[200005];
int main(){
    freopen("string.in", "r",stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cin >> c[i];
    }
    for(int i = 1, j = n; i <=j;){
        if(c[i] == c[j]){
            int tmp = min(a[i], a[j]);
            a[i] -= tmp;
            a[j] -= tmp;
        }
        else{
            int tmp = min(a[i], a[j]);
            ans += tmp;
            a[i] -= tmp;
            a[j] -= tmp;
        }
        if(a[i] <= 0) i++;
        if(a[j] <= 0) j--;
    }
    cout << ans;
    return 0;
}
