#include <bits/stdc++.h>
using namespace std;

const int mx=5*1e5+5;
int nrr[mx];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>nrr[i];
    sort(nrr,nrr+n);
    long long rt=nrr[1]-nrr[0];
    for(int i=0;i<n;i++){
        ans=1LL*rt*(i+1)*i/2;
        if(ans>m){cout<<i<<'\n';break;}
        if(i==n-1){cout<<i+1<<'\n';break;}
    }

    return 0;
}
