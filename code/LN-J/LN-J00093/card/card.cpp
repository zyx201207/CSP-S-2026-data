#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 5e5 + 10;
ll vis[MAX],res[MAX],lst[MAX],num[MAX];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m,t=1,A=1,B=0;
    cin >> n >> m;
    //A
    for (ll i=0;i<n;i++){
        cin >> num[i];
        if (num[i] < num[i-1]) A=0;
    }
    if (A == 1){
        for(ll i=0;i<n;i++){
            if (vis[num[i]] == 0){
                res[num[i]] = n-i;
                vis[num[i]] = 1;
            }
        }
    }
    if (m == 1){
        cout << n;
        return 0;
    }
    if (m == 2){
        if (num[n-1] == 1){
            for (ll i=0;i<n;i++){
                if (num[i] == 1){
                    res[1]++;
                }
                if (num[i] == 2){
                    res[1]++;
                    res[2]++;
                }
            }
            cout << res[1] << ' ' << res[2];
            return 0;
        }
        if (num[n-1] == 2){
            for (ll i=0;i<n;i++){
                if (num[i] == 1){
                    res[1]++;
                    res[2]++;
                }
                if (num[i] == 2){
                    res[2]++;
                }
            }
            cout << res[1] << ' ' << res[2];
            return 0;
        }
    }
    for (ll i=1;i<=m;i++) cout << res[i] << ' ';

    return 0;
}
