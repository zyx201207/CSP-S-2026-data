#include<bits/stdc++.h>
#define int long long
#define inf 4000000000000000000ll
using namespace std;
int c,T,n,d,a[2000005],ans,lst,p,pre[2000005],nxt[2000005],cntl[2000005],cntr[2000005],dp1[2000005],dp2[2000005],sum1[2000005],sum2[2000005];
struct Rectangle{
    int lx,ly,rx,ry;
    bool notempty(){return lx<=rx&&ly<=ry;}
    int query(int p){
        if(!notempty())return 0;
        int res=max(rx-lx+1,0ll)*max(ry-ly+1,0ll);
        //cout<<(a[p]-a[lx-1]>d)<<" "<<(a[ry+1]-a[p+1]>d)<<"\n";
        if(a[ry+1]-a[p+1]>d)res+=(dp2[ry]-1)*max(rx-lx+1,0ll);
        if(a[p]-a[lx-1]>d)res+=(dp1[lx]-1)*max(ry-ly+1,0ll);
        if(a[ry+1]-a[p+1]>d&&a[p]-a[lx-1]>d)res+=(dp1[lx]-1)*(dp2[ry]-1);
        return res;
    }
    //friend int intersect(Rectangle x,Rectangle y){return x.notempty()*y.notempty()*((Rectangle){y.lx,y.ly,x.rx,x.ry}).query();}
}b[2000005],base=(Rectangle){0,0,0,0};
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        pre[0]=0;nxt[n+1]=n+1;
        dp1[0]=1;dp2[n+1]=1;
        sum1[0]=0;sum2[0]=0;
        a[0]=-inf;a[n+1]=inf;b[0]=base;lst=0;
        for(int i=1;i<=n;i++)cntl[i]=cntr[i]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1];
            while(a[i]-a[pre[i]]>d)pre[i]++;
        }
        for(int i=n;i>=1;i--){
            nxt[i]=nxt[i+1];
            while(a[nxt[i]]-a[i]>d)nxt[i]--;
        }
        for(int i=1;i<=n;i++)cntl[pre[i]]++;
        for(int i=1;i<=n;i++)cntr[nxt[i]]++;
        for(int i=1;i<=n;i++){
            dp1[i]=cntr[i]+1-(nxt[i]==i);
            if(nxt[pre[i]]==i)dp1[i]+=dp1[pre[i]]-1;
            //cout<<i<<":"<<dp1[i]<<"\n";
        }
        for(int i=n;i>=1;i--){
            dp2[i]=cntl[i]+1-(pre[i]==i);
            if(pre[nxt[i]]==i)dp2[i]+=dp2[nxt[i]]-1;
        }
        for(int i=1;i<=n;i++){
            sum1[i]=sum1[i-1]+dp1[i];
            sum2[i]=sum2[i-1]+dp2[i];
            //cout<<i<<":"<<dp2[i]<<"\n";
        }
        for(int i=1;i<n;i++){
            b[i]=b[i-1];
            while(a[b[i].lx]<a[i+1]-d)b[i].lx++;
            while(a[b[i].ly]<a[i-1]+d+1)b[i].ly++;b[i].ly=max(b[i].ly,i+2);
            while(a[b[i].rx+1]<=a[i+2]-d-1&&b[i].rx+1<i)b[i].rx++;
            while(a[b[i].ry+1]<=a[i]+d)b[i].ry++;
            ans+=b[i].query(i);
            //if(i>lst+1)ans-=2*intersect(b[i-1],b[i]);
            //if(i>lst+2)ans+=intersect(b[i-2],b[i]);
            //cout<<i<<":"<<b[i].lx<<"~"<<b[i].rx<<"&"<<b[i].ly<<"~"<<b[i].ry<<"\n";
        }cout<<ans<<"\n";
    }
}
/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
*/
