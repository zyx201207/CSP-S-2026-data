#include<bits/stdc++.h>
#define int long long
const int N=1e5+10;
using namespace std;
int n,m,a[N],c[N];
signed main(){
    // freopen("aaa.in","r",stdin);
    // freopen("aaa.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=c[i-1]+a[i];
    }
    cout<<c[n];
    return 0;
}//5 5 1 2 3 4 5