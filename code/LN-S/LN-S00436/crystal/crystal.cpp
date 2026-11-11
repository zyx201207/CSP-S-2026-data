#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[500009];
ll sum[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum[1]=0;
    for(int i=2;i<=n;++i){
        sum[i]=a[i]-a[i-1];
    }
    ll t=0,num=1,lft=0;
    for(int i=2;i<=n;++i){
        t+=sum[i]*num;
        while(t>m){
            lft++;
            num--;
            t-=a[i]-a[lft];
        }
        if(t<=m){
            num++;
            ans=max(num,ans);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
