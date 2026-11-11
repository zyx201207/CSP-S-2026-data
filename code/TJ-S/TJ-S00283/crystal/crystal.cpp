#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N=1e6+10;
#define For(a,b,c) for(int a=(b);a<=(LL)(c);a++)
#define Rep(a,b,c) for(int a=(b);a>=(LL)(c);a--)

template <typename T> void tomin(T &a,const T &b){a=a<b?a:b;}
template <typename T> void tomax(T &a,const T &b){a=b<a?a:b;}

template <typename T> void read(T &x){
    T f=0,w=1;
    int ch=getchar();
    while(!isdigit(ch)){if(ch=='-') w=-w;ch=getchar();}
    while(isdigit(ch)) {f=(f<<3)+(f<<1)+ch-48;ch=getchar();}
    x=f*w;
}

LL a[N];
LL sum[N];

void awa(){
    int n;LL m;
    read(n),read(m);
    For(i,1,n) read(a[i]);
    sort(a+1,a+1+n);
    For(i,1,n) sum[i]=sum[i-1]+a[i];
    int res=0;
    For(i,1,n){
        //if the basic shuijing is i
        int l=1,r=i-1,ans=i;
        while(l<=r){
            int mid=(l+r)>>1;
            LL w=a[i]*(i-mid+1) - (sum[i]-sum[mid-1]);
            // cerr<<"i="<<i<<" mid="<<mid<<" w="<<w<<" sum="<<(sum[i]-sum[mid-1]) <<"\n";
            if(w<=m) ans=mid,r=mid-1;
            else l=mid+1;
        }
        // cerr<<"i="<<i<<" ans="<<ans<<"\n";
        tomax(res,i-ans+1);
    }
    printf("%d\n",res);
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;
    // read(T);
    while(T--) awa();
    return 0;
}
/*
Why Linux can't input Chinese?
Ohhhh no!

14:57
*/