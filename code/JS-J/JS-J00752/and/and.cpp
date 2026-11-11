#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    /*int i ,j;
    cin>>i>>j;
     ll a[10];
    ll n=1;
    while(i!=0){
       a[n]=i%2;
       i=i/2;
       n=n+1;
       if(i==0){
          a[n+1]=a[n];
       }
    }
    ll b[10];
    ll m=1;
    while(j!=0){
       b[m]=j%2;
       j=j/2;
       m=m+1;
       if(j==0){
          b[m+1]=b[m];
       }
    }
    ll cc=max(n,m);
    ll c[cc];
    ll z=0;
    for(ll k1=cc;k1>=1;k1--){
        z=z+1;
        if(a[k1]==1&&b[k1]==1)c[z]=1;
        else if(a[k1]==0&&b[k1]==0)c[z]=0;
        else c[z]=0;
    }
    ll da=0;
    for(ll i=z;i>=1;i--){
        ll y=i-z;
        da=da+2^y;
    }
    cout<<da<<endl;*/
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    ll a[n];
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[m]<<endl;
    return 0;
}
