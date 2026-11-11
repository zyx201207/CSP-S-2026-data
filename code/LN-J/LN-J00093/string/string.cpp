#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 2e5 + 10;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,m,a,l,r,res=0,lst[MAX][2]; char c;
    cin >> n;
    l = 0; r = n-1;
    for (ll i=0;i<n;i++){
        cin >> lst[i][0] >> c;
        lst[i][1] = c - 'a';
    }
    for (ll i=0;;i++){
        m = min(lst[l][0],lst[r][0]);
        if (lst[l][1] != lst[r][1]){
            res += m;
        }
        lst[l][0] -= m;
        lst[r][0] -= m;
        if (lst[l][0] == 0) l++;
        if (lst[r][0] == 0) r--;
        if (l >= r) break;
    }
    cout << res;
}


