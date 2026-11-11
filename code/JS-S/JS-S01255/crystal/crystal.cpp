#include<bits/stdc++.h>
#define int long long
#define get() getchar()
#define put(ch) putchar(ch)
using namespace std;
inline int read(){int x=0,f=1;char ch=get();while(ch!=EOF&&(ch<'0'||ch>'9')){if(ch=='-')f=-1;ch=get();}while(ch>='0'&&ch<='9')x=x*10+(ch^'0'),ch=get();return x*f;}
inline void write(int x){if(x<0)put('-'),x=-x;if(x>=10)write(x/10);put((x%10)^'0');}
int a[500005],s[500005];
void main1(){
    int n=read(),m=read(),ans=0;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;++i){
        int l=1,r=i,mid;
        while(l<=r){
            mid=l+r>>1;
            if(s[i]-s[mid-1]+m>=a[i]*(i-mid+1)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    write(ans);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int t=1;
    while(t--){
        main1();
        put('\n');
    }
    return 0;
}
