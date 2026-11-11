#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans;
struct Node{
    ll x;
    char c;
}a[200005];
bool vis[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].c;
    }
    ll i = 1, j = n, k1 = 0, k2 = 0;
    while(i >= 1 && j <= n && i < j){
        if(!vis[i])k1 += a[i].x;
        if(!vis[j])k2 += a[j].x;
        vis[i] = vis[j] = 1;
        if(k1 > k2){
            if(a[i].c != a[j].c)ans += k2;
            k1 -= k2;
            k2 = 0;
            j--;
        }else if(k1 < k2){
            if(a[i].c != a[j].c)ans += k1;
            k2 -= k1;
            k1 = 0;
            i++;
        }else{
            if(a[i].c != a[j].c)ans += k1;
            k1 = k2 = 0;
            i++, j--;
        }
    }
    cout << ans;
    return 0;
}
