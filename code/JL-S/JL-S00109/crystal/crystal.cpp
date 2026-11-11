#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,zxh,xh;
ll a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll check=a[2]-a[1];

    ll times=0;
    while(zxh<m){
        times++;
        zxh+=(xh+a[times+1]-a[times]);
        xh++;
        //cout<<zxh<<" "<<xh<<"\n";
    }
    int imaier=a[1]+xh-1;
    for(int i=times+1;i<=n;i++){
        if(imaier!=a[i])break;
        xh++;
    }

    cout<<xh<<"\n";
    return 0;
}
