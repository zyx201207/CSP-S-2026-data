#include <bits/stdc++.h>
#define int long long
using namespace std;
struct qj{
    int st;
    int en;
    int sl;
    char c;
}a[200005];
int n,x,t1,t2,t;
int rrr;
char ch;
signed main()
{
    freopen("string6.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>ch;
        a[i].st=a[i-1].en+1;
        a[i].en=a[i-1].en+x;
        a[i].c=ch;
        a[i].sl=x;
        rrr+=x;
    }
    int rr=rrr-rrr/2;
    t1=1,t2=n;
    if(!(rrr&1)){
        rr++;
    }
    /*for(int i=1;i<=n;i++){
        if(a[i].st<=rr&&a[i].en>=rr){
            t=i;
            /*if(!(r&1)){
                t1++;
                t--;
            }
            break;
        }
    }
    /*if(a[t].en!=rr){
        a[n+1]=a[t];
        a[n+1].st=rr+1;
        a[t].en=rr-1;
    }
    for(int i=n+1;i<=t+2;i++){
        swap(a[i],a[i-1]);
    }*/

    int ans=0,r=rrr,l=1;
    qj tt;
    while(l<=r){
            //printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld\n",rrr,l,r,t1,t2,a[t1].en,a[t2].st,a[t1].sl,a[t2].sl);
        if(l>a[t1].en){
            t1++;
        }
        if(r<a[t2].st){
            t2--;
        }
        if(a[t1].sl>a[t2].sl){
            tt=a[t2];
        }
        else{
            tt=a[t1];
        }
        if(a[t1].c!=a[t2].c){
            ans+=tt.sl;
        }
        if(a[t1].sl>a[t2].sl){
            r=tt.st-1;
            l=rrr-r+1;
            a[t1].st=l;
            a[t1].sl-=tt.sl;
        }
        else{
            l=tt.en+1;
            r=rrr-l+1;
            if(a[t1].sl!=a[t2].sl){
                a[t2].en=r;
            }else{
                a[t2].en=r+1;
            }
            a[t2].sl-=tt.sl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
