#include<bits/stdc++.h>
#define LL long long
using namespace std;
namespace fastIO{
    const int N=1<<20;
    char buf[N],*p1=buf,*p2=buf;
    inline char getchar(){
        if(p1==p2){
            p2=(p1=buf)+fread(buf,1,N,stdin);
            if(p1==p2)return EOF;
        }
        return *p1++;
    }
    inline LL read(){
        LL x=0,f=1;
        char ch=getchar();
        while(ch<'0'||ch>'9'){
            if(ch=='-')f=-1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=(x<<1)+(x<<3)+(ch^48);
            ch=getchar();
        }
        return x*f;
    }
}
const int N=5e5+5;
LL n,m,a[N],R,L,sum[N];
bool flag;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=fastIO::read();
    m=fastIO::read();
    for(int i=1;i<=n;i++)a[i]=fastIO::read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    R=n;
    L=1;
    while(1){
        if(L>=R-1)break;
        flag=0;
        LL mid=(L+R)>>1;
        for(LL i=mid;i<=n;i++){
            if(mid*a[i]-sum[i]<=m){
                L=mid;
                flag=1;
                break;
            }
        }
        if(!flag)R=mid;
    }
    cout<<L<<'\n';
    return 0;
}
