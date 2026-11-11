#include<bits/stdc++.h>
#define int long long
#define il inline
using namespace std;
const int N=5e5+20;
il int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
int a[N];
int s[N];
int ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i+1;
        while(l<r){
            int mid=(l+r)>>1;
            int len=i-mid+1;
            if((len*a[i]-s[i]+s[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
