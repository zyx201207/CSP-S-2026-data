#include <bits/stdc++.h>
using namespace std;
long long a[514514];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,mx=1;
    long long m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    __int128 sum=0;
    while(sum<=m&&mx<=n){
        sum+=__int128(abs(a[mx+1]-a[mx]))*mx;
        mx++;
    }
    cout << mx-1;
    return 0;
}
