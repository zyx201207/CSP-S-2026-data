#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int read(){
    int x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c-'0');
        c=getchar_unlocked();
    }
    return x*f;
}
int n,m,a[N],b[N];
int maxn=-6666666;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        int mid;
        while(l<=r){
            mid=l+r>>1;
            if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m) r=mid-1;
            else l=mid+1;
        }
        maxn=max(maxn,i-mid+1);
    }
    printf("%lld",maxn);
    return 0;
}
//16:30
//fk,what is this
//sometimes #3 +1
//sometimes #4
//fk,how much i can get?
