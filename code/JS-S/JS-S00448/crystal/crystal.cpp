#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=0,maxn=500005;
int read(){
    int f=1,k=0,c=getchar_unlocked();
    for(;!isdigit(c);c=getchar_unlocked()){
        if(c=='-'){
            f=-1;
        }
    }
    for(;isdigit(c);c=getchar_unlocked()){
        k=k*10+(c^48);
    }
    return f*k;
}
int n,a[maxn],s[maxn],m,ans;
int l,r;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int zws;
    l=1;
    for(int i=1;i<=n;i++){
        r=i;
        zws=a[r];
        int id=r;
        int s1=s[id]-s[l-1],s2=s[r]-s[id],cur=zws*(id-l+1)-s1+s2-zws*(r-id);
        while(l<=r&&m<cur){
            l++;
            s1=s[id]-s[l-1],s2=s[r]-s[id],cur=zws*(id-l+1)-s1+s2-zws*(r-id);
        }
        ans=max(ans,r-l+1);
    }
    printf("%lld",ans);
    return 0;
}
/*
5 6
-3 -1 2 2 7
*/

/* 15:30
I just finished it,do u know why?
I think it can +1 and -1 but it only can +1
I'm blind

and
zhi chi x x xxx yi zhou nian xie xie miao(?
*/
