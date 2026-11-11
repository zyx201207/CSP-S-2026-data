#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m,a[N],ans=1,tot,q[N],hd=1,tl;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);tl++;q[tl]=a[1];
    for(int i=2;i<=n;i++){
        tot+=(a[i]-a[i-1])*(tl-hd+1);
        while(tot>m&&hd<=tl){
            tot-=a[i]-q[hd];
            hd++;
        }
        tl++;
        q[tl]=a[i];
        ans=max(ans,tl-hd+1);
    }
    cout<<ans;
    return 0;
}