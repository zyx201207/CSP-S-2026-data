#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[500015],b[500015],ans;
bool f1,f2;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;f1=f2=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(f1)if(a[i]!=i)f1=0;
        if(f2)if(i>2)if(a[i]-a[i-1]!=a[i-1]-a[i-2])f2=0;
    }
    if(f1){cout<<min((m+(m&1))/2+1,n);}
    else if(f2){
        ll dc=a[2]-a[1];
        if(m>=dc&&m<dc*3)cout<<2;
        else if(m<dc)cout<<1;
        else{
            cout<<min((m-dc)/(dc*2)+1,n);
        }
    }
    else{
        sort(a+1,a+n+1);ans=1;
        for(ll i=1;i<=n;i++)b[i]=b[i-1]+a[i];
        for(ll i=1;i<=n;i++)for(ll j=i+ans-1;j<=n&&j-i+1>=ans&&(j-i+1)*a[j]-b[j]+b[i-1]<=m;j++)if(j-i+1>ans)ans=j-i+1;
        cout<<ans;
    }

    return 0;
}
