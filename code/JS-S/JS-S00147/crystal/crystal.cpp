#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],sum=0,anss,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll flag=0;
    for(ll i=1;i<=n;i++){
        ll del=a[i]*(i-1);
        //cout<<del-sum<<" ";
        if(del-sum>=m){
            anss=del-sum;
            ll x=i+1;
            ans=i;
            while(x>=m){
                if(a[i]==a[x]){
                    ans++;
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        sum+=a[i];
        if(flag)break;
    }
    //cout<<1<<"\n";
    if(anss==m)cout<<ans;
    else{
        ans--;
        cout<<ans;
    }
    return 0;
}

