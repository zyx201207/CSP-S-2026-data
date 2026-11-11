#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[600000];
int cf[400000];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    cf[1]+=n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        cf[1]--;
        cf[x]++;
    }
    for(int i=1;i<=m;i++){
        cf[i]+=cf[i-1];
        cout<<cf[i]<<" ";
    }
    return 0;
}
