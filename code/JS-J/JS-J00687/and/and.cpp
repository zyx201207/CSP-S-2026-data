#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2020];
ll liangliangdeyihuo[2000005];
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    else if(m==2){
        ll maxans=0;
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                maxans=max(maxans,(a[i]&a[j]));
            }
        }
        cout<<maxans;
        return 0;
    }
    else if(m==n){
        ll ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(m==n-1){
        ll minh=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                minh=min(minh,(a[i]&a[j]));
            }
        }
        ll ans2=a[1];
        bool flag=0;
        for(int i=2;i<=n;i++){
            if((ans2&a[i])==minh&&flag==0){
                flag=1;
            }
            else{
                ans2&=a[i];
            }
        }
        cout<<ans2;
        return 0;
    }
    else{
        ll u=1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                liangliangdeyihuo[u]=(a[i]&a[j]);
                u++;
            }
        }
        sort(liangliangdeyihuo+1,liangliangdeyihuo+u,cmp);
        cout<<liangliangdeyihuo[m];
        return 0;
    }
    return 0;
}
