#include<bits/stdc++.h>
#define ll long long
#define love return
#define CCF 0
using namespace std;
const int N=5e5+5;
int n,m;
ll a[N],sum=0,mx=-1e18;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=2,j=1;i<=n;i++){
        ll x=1ll*(a[i]-a[i-1])*(i-j);
        if(sum+x>m){
            mx=max(mx,i-j);
            while(sum+x>m){
                sum-=(a[i]-a[j]);
                j++;
            }
        }
        sum+=x;
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    love CCF;
}
//100pts
