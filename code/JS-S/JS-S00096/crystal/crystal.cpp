#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010];
long long h[500010];
long long l=0x3f3f3f3f,r=-0x3f3f3f3f,cnt,mid;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9'){x=x*10+c-48;c=getchar();}
    return x*f;
}int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1; i<=n; i++){
        a[i]=read();
        l=min(l,a[i]);
        r=max(r,a[i]);
    }//cout<<l<<' '<<r<<endl;
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) h[i]=h[i-1]+a[i];
    while(l<r){
        mid=(l+r)/2;
        int ll=0,rr=n;
        while(ll<rr){
            int midd=(ll+rr)/2;
            if(a[midd]>mid) rr=midd;
            else ll=midd+1;
        }ll--;
        cnt=ll*mid-h[ll];
        //cout<<mid<<' '<<ll<<' '<<cnt<<' '<<l<<' '<<r<<endl;
        if(cnt<=m) l=mid+1;
        else r=mid-1;
    }
    for(int i=1; i<=n; i++) if(a[i]<=mid) ans++;
    cout<<ans;
}
