#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans1,ans2;
ll a[510000],q[510000],maxn=1,maxj;
char s;
ll read(){
    ll k=1,k1=0;
    s=getchar();
    while(s<'0' || s>'9'){
        k=-1;
        s=getchar();
    }
    while(s>='0' && s<='9'){
        k1=k1*10+(s-'0');
        s=getchar();
    }
    return k1*k;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    n=read();
    m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
   for(ll i=1;i<=n;i++){
        maxj=maxn-1;
        for(ll j=i+maxn-1;j<=n;j++){
            ans1=q[j]-q[i-1]+m;
            ans2=a[j]*(j-i+1);
            if(ans1<ans2){
                break;
            }else{
                maxj+=1;
            }
        }
        //cout<<i<<" "<<maxj<<endl;
        maxn=max(maxn,maxj);
    }
    cout<<maxn;
    return 0;
}

//he yi wei
//li wang hong  js-xx nan
//xve xiao: xing hai gao ji zhong xve
//shen feng zheng :320723xxxxxxxx0313
