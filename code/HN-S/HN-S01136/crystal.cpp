#include<bits/stdc++.h>
#define mid (l+((r-l)>>1))
#define ls (p<<1)
#define rs (ls|1)
#define lt ls,l,mid
#define rt rs,mid+1,r
#define int long long
using namespace std;
const int N=1e6+5;
int a[N],ans,sum[N];

inline int read(){
    int a=1,b=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') a=-a;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        b=(b<<1)+(b<<3)+(ch^48);
        ch=getchar();
    }
    return a*b;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    // int l=1;
    int res=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i,ans=i;
        while(l<=r){
            // if(i==3) cout<<l<<" "<<r<<" "<<a[i]*(i-mid)<<" "<<(sum[i-1]-sum[mid-1])<<endl;
            if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1]) <=m) ans=mid,r=mid-1;
            else l=mid+1;
        }
        // cout<<i<<" "<<ans<<endl;
        res=max(res,i-ans+1);
        // while()
        // int l=1,r=i;
        // while(l<)
    }
    printf("%lld\n",res);
    // int now=0,r=1;
    // for(int i=1;i<=n;i++){
    //     if(now+(a[i]-a[1])>m) break;
    //     now+=a[i]-a[1];
    //     r=i;
    // } 
    // ans=r;
    // int l=1,lcnt=0,rcnt=r-1;
    // for(int i=2;i<=n;i++){
    //     lcnt++,rcnt--;
    //     now=(sum[r]-sum[i])-a[i]*rcnt+a[i]*lcnt-(sum[i-1]-sum[l]);
    //     while(now>m&&l<=r){
    //         now-=(a[i]-a[l]);
    //         l++;
    //     }
    //     while(r+1<=n&&now+a[r+1]<=m){
    //         r++;
    //         now+=(a[r]-a[i]);
    //     }
    //     while(l+1<=i&&r+1<=n&&a[r+1]-a[i]<=a[i]-a[l]){
    //         now+=(a[++r]-a[i]);
    //         now-=(a[i]-a[l++]);
    //         while(r+1<=n) {
    //             r++;
    //             now+=(a[r]-a[i]);
    //         }
    //     }
    //     ans=max(ans,r-l+1);
    // } 
    // printf("%lld\n",ans);
    return 0;
}