#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int n,m;
int a[N + 5],prefix[N + 5];
bool check(int p){
    for(int i = p;i <= n;i++){
        if(m >= a[i] * p - (prefix[i] - prefix[i - p]))
            return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++)
        prefix[i] = prefix[i - 1] + a[i];
    
    int lft = 1,rgt = n;
    while(lft <= rgt){
        int mid = (lft + rgt) >> 1;
        if(check(mid))
            lft = mid + 1;
        else
            rgt = mid - 1;
    }
    if(check(lft))
        cout << lft << '\n';
    else
        cout << lft - 1 << '\n';
}