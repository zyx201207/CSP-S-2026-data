#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll const MAX = 5e5 + 10;
ll lst[MAX];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ull n,m,l=0,r=0,lenth=1,res=0;
    cin >> n >> m;
    for (ll i=0;i<n;i++){
        cin >> lst[i];
    }
    sort(lst,lst+n);
    while (1){
        for (ll i=0;;i++){
            if (r == n-1) break;
            if ((lst[r+1]-lst[r])*lenth<=m){
                m -= (lst[r+1]-lst[r])*lenth;
                lenth++; r++;
            }
            else break;
        }

        if (res < lenth) res = lenth;
        if (r == n-1) break;
        m += lst[r] - lst[l];
        l++; lenth--;
    }
    cout << res;
    return 0;
}
