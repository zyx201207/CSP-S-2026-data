#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+6;

ll qread(){
    char ch=getchar();ll x=0,f=1;
    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=(x*10)+ch-48;ch=getchar();}
    return f*x;
}

ll a[N]={0},c[N]={0};

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ll n=qread(),m=qread(),ind;
    for(int i=0;i<n;i++){
        a[i]=qread();
    }

    sort(a,a+n);

    for(int i=1;i<n;i++){
        c[i]=i*(a[i]-a[i-1])+c[i-1];
        if(c[i]>m) {ind=i;break;}
    }
    //for(int i=0;i<n;i++) cout<<c[i]<<" ";

    ll ans=ind,c1=c[ind-1];
    for(ll i=a[ind-1]+1;i<=a[ind];i++){
        c1=(i-a[ind-1])*ind+c[ind-1];
        ll k=0,res=ind;
        while(c1>m){
            c1-=(i-a[k]);
            k++;res--;
        }
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}
