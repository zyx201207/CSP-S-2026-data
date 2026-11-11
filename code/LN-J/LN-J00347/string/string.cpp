#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
ll T,n;
ll a[200005];
ll c[200005];
ll ans;
int main(){
//cout<<1;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
  //  cout<<1;
    //cin>>T;
    T=1;
    while(T--){
            ans=0;
        ll n;
        cin>>n;
        f(i,1,n){
            char cc;
            cin>>a[i]>>cc;
            c[i]=cc-'a';
        }
        ll l=1,r=n,suml=0,sumr=0;
        while(r>=l)
            if(suml<=sumr){
                if(c[r-1]!=c[l]) ans+=min(sumr-suml,a[l]);
                suml+=a[l];
                l++;
            }else{
                if(c[r]!=c[l-1]) ans+=min(suml-sumr,a[r]);
                sumr+=a[r];
                r--;
            }
        cout<<ans;
        }

    return 0;
}

