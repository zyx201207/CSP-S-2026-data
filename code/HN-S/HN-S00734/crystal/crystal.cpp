#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005];
int read(){
    int res=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
    while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
    return res*f;
}
bool check(int x){
    for(int i=x;i<=n;++i)
        if(x*a[i]-s[i]+s[i-x]<=m)
            return 1;
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;s[i]=s[i-1]+a[i],++i);
    int l=1,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    printf("%lld",l);
    return 0;
}