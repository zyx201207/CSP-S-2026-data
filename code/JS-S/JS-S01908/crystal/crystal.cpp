#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long x=0,f=1;char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-') f=-1;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f*x;
}
const long long N=5e5+10;
long long n,m,a[N],sum[N];
bool check(long long l,long long r){
    long long res=(r-l+1)*a[r]-sum[r]+sum[l-1];
    if(res<=m) return true;
    return false;
}
long long work(long long sr){
    long long l=1,r=sr,s=sr;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(check(mid,sr)){
            s=mid;r=mid-1;
        }
        else l=mid+1;
    }
    return sr-s+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    long long ans=0;
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        ans=max(ans,work(i));
    }
    cout<<ans<<endl;
    return 0;
}