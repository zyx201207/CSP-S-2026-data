#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
void write(long long x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
long long n,m,a[maxn],sum[maxn];
int bisearch(int x){
    int l=1,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(sum[x]-sum[mid]-(a[x]-a[mid])*(mid-1)<=m){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i) sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
    int ans=1;
    for(int i=n;i>=1;--i){
        int pos=bisearch(i);
        if(pos==-1) continue;
        else ans=max(ans,i-pos+1);
    }
    write(ans);
    return 0;
}
