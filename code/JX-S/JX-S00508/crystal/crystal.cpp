#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1),pre(n+1);
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a.begin()+1,a.begin()+n+1);
    for(ll i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    ll k=0;
    for(ll i=1;i<=n;i++)
        if(m<(i-1)*a[i]-pre[i-1]){
            k=i-1;
            break;
        }
    ll ans=k,summ=k;
    for(ll i=1,j=k;j<=n;i++,j++){
        ll sum=(k-1)*a[j]-pre[j-1]+pre[i-1];
        if(sum>m)
            continue;
        bool flag1=true,flag2=true;
        ll ii=i,jj=j;
        while(flag1||flag2){
            if(flag1){
                if(jj+1<=n){
                    jj++;
                    sum=(jj-ii)*a[jj]-pre[jj-1]+pre[ii-1];
                    if(sum>m)
                        flag1=false;
                    else
                        k++;
                    }else
                        flag1=false;
            }
            if(flag2){
                if(ii-1>=1){
                    ii--;
                    sum=(jj-ii)*a[jj]-pre[jj-1]+pre[ii-1];
                    if(sum>m)
                        flag2=false;
                    else
                        k++;
                }else
                    flag2=false;
            }
        }
        ans=max(ans,k);
        k=summ;
    }
    cout<<ans<<'\n';
    return 0;
}
