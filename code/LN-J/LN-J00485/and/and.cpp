#include <bits/stdc++.h>
using namespace std;
int n , m;
int a[200010];
int ans;
bool cmp(int a , int b){
return a > b;}
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w", stdout);
    cin >> n >> m;
    int maxn = INT_MIN , minp = INT_MAX;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        if(a[i] > maxn){
            maxn = a[i];
        }
        if(a[i] < minp){
            minp = a[i];
        }
    }
    sort(a + 1 , a + n + 1 , cmp);
    if(m == 1){
        cout<< maxn;
        return 0;
    }
    if(m == n - 1){
        ans = a[1];
        for(int i = 1;i <= n - 1;i ++){
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    if(m == 2){
        ans = a[1] & a[2];
        cout << ans;
        return 0;
    }
    for(int i = 1;i <= m;i ++){
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
