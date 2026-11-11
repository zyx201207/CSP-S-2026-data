#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int n;
ll d,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    scanf("%d%d",&t,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",a+i);
        ll ans=0;
        for(int i=1;i<=n;i++){
            int lsg=i,ldu=-1,ltb=-1;
            int sg,du,tb;
            for(ll j=d;j<=a[n]-a[1];j+=d){
                if(lsg==-1&&ldu==-1)break;
                if(lsg>0){
                    if(a[lsg]-d<=a[1])break;
                    int tr=lower_bound(a+1,a+n+1,a[lsg]-d)-a;
                    if(a[lsg]-a[tr]>d)tr++;
                    if(lsg==tr)break;
                    sg=lower_bound(a+1,a+n+1,a[tr]-d)-a;
                    if(a[sg]-a[tr]>d)sg++;
                    if(sg==tr)break;
                    if(tr+1==lsg)du=-1;
                    else{
                        du=lower_bound(a+1,a+n+1,a[tr+1]-d)-a;
                        if(a[du]-a[tr+1]>d)du++;
                        if(du<=sg)sg=-1;
                    }if(tr+2>=lsg)tb=tr;
                    else{
                        int tb=lower_bound(a+1,a+n+1,a[tr+2]-d)-a;
                        if(a[tb]-a[tr+2]>d)tb++;
                        if(tb<=du)break;
                    }if(du>0)ans+=tb-du;
                }else{
                    int tr=lower_bound(a+1,a+n+1,a[ldu]-d)-a;
                    if(a[ldu]-a[tr]>d)tr++;
                    if(ldu==tr)break;
                    du=lower_bound(a+1,a+n+1,a[tr]-d)-a;
                    if(a[du]-a[tr]>d)du++;
                    if(du==tr)break;
                    if(tr+1>=ldu)tb=tr;
                    else{
                        int tb=lower_bound(a+1,a+n+1,a[tr+1]-d)-a;
                        if(a[tb]-a[tr+1]>d)tb++;
                        if(tb<=du)break;
                    }ans+=tb-du;
                }lsg=sg;
                ldu=du;
            }
        }printf("%lld\n",ans);
    }return 0;
}