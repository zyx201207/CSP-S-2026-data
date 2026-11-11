#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
long long a[N],s[N],c[N],big=1e6,r,sum=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll d=a[1]-a[0]; bool f=1;
    for(int i=1;i<n;i++){
        c[i]=abs(a[i]-a[i-1]);
        if(c[i]!=d) f=0;

        if(c[i]==1){
            sum++;
        }

    }
    c[n]=N;

    if(sum==n-1){
        ll i=1;
        while(m>0){
            m=m-i;
            i++;
        }
        cout<<i-1;
        return 0;
    }
    if(f==1){
        ll i=d,z=1;

        while(m>0){
            m-=d*z;
            z++;
        }
        cout<<z-1;
        return 0;
    }

    ll he=0,co=1,maxn=-1;
    for(int i=0;i<n;i++){
        he=0;co=1;
            for(int j=i;j<n;j++){
                he+=c[j+1]*co;

                if(he>m) break;
                co++;
            }


        maxn=max(maxn,co);
    }


    cout<<maxn;
    return 0;
}
