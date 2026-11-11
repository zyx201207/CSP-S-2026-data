#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500000+9],s[500000+9],he[500000+9],summ=0,anss=0;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);

    for(ll i=1;i<=n;i++){
        s[i]=a[i+1]-a[i];
        he[i]=s[i]+he[i-1];
    }
    he[n]=10000;
    ll l=n-1,r=n-1;
    while(--l){
        summ+=he[r-1]-he[l-1];
        if(summ>m){
            while(r){
                summ-=(he[r-1]-he[r-2])*(r-l);
                r--;
                if(l==r||summ<=m){
                    if(r-l+1>anss) anss=l-r+1;
                    break;
                }
            }
        }
        else{
            anss=max(anss,r-l+1);
        }
        if(l==1){
            while(r){
                summ-=(he[r-1]-he[r-2])*(r-l);
                r--;
                if(l==r||summ<=m){
                    if(r-l+1>anss) anss=l-r+1;
                    break;
                }
            }
            break;
        }
    }
    cout<<anss;
    return 0;
}
