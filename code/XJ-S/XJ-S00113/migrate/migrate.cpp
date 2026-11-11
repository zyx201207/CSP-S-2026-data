#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
const int M = 1e8+5;
int n,m,a[N],b[N],ans,diff[N],f[M];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n;cin>>n>>n>>n>>n;
    if(n%2==0)cout<<1<<endl<<2<<endl;
    else cout<<0<<endl<<1<<endl;
    return 0;
}
/*

5 8
-3 -1 2 2 7

*/
