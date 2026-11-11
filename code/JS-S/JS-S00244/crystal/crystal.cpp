#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=500011;
const int inf=0x3f3f3f3f;
ll n,m,a[N],f[N],pre[N],suf[N];

bool cmp(const ll &x,const ll &y){
    return x<y;
}
ll maxv=-inf;
int cnt[100011],soo[100011];
ll ans1=-inf,ans2=-inf;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],maxv=max(maxv,a[i]);
    //cout<<maxv<<"\n";
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) pre[i]=a[i]-a[i-1];
    f[1]=0;
    for(ll i=2;i<=n;i++)
        f[i]=f[i-1]+1LL*(i-1)*pre[i];
    ll pos=upper_bound(f+1,f+n+1,m)-f;
    ans1=pos-1;

    int mvv=-inf,mst=0;
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    for(int i=1;i<=100000;i++){
        if(mvv<cnt[i]) mvv=cnt[i],mst=i;
    }//most count number
    for(int i=1;i<=n;i++){
        if(a[i]<=mst) soo[i]=mst-a[i];
//           cout<<soo[i]<<"\n";
    }
    sort(soo+1,soo+n+1);
    for(int i=1;i<=n;i++) suf[i]=suf[i-1]+soo[i];
    ll pos1=upper_bound(suf+1,suf+n+1,m)-suf;
    ans2=pos1-1;

    cout<<max(ans1,ans2)<<"\n";

    return 0;
//    cout<<pos<<"\n";
//    for(int i=1;i<=n;i++) cout<<f[i]<<" ";
}
//I want to cry, my mum says I only need my phone.I am suffering.I don't concentrate on the OI, I look much bad things. I regret but it cannot work.It's 18:19 now, I don't know if others will laugh at me.I copy others code, I ask for AI often.
//I will tell all this to my family tonight. how to open my mouth. I have realized that if I do not say it, I will keep down in my life until I'm died.
/*
OK, I think good.

use pre arr, get the position.

output position-1

#1 ok, #2 ok, #3 ok.

?!#4 Wa.?!

maybe find the count most num, greedy.

ok, 30 minutes later.

?!segmentation fault?!

?!ququ?!

now 15:40, can I win?

maybe i really need to concentrate on my study, i forget my dijkstra.

I'm tired out.
*/
//111111111111111111111111111111111111111111111111111111111111111111111
