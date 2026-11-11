#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__);
struct FSI{
    template<typename T>
    FSI& operator >> (T&res){
        res=0;T f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
        while(isdigit(ch)){res=(res*10)+(ch-48);ch=getchar();}
        res*=f;
        return *this;
    }
} scan;
typedef long long ll;
const int N=5e5+5;
ll a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    scan>>n>>m;
    for(int i=1;i<=n;i++) scan>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int res=0;
    for(int r=n;r>=1;r--){
        int L=0,R=r;
        while(L<R){
            int mid=(L+R)>>1;
            if((r-mid)*a[r]-(sum[r]-sum[mid])<=m) R=mid;
            else L=mid+1;
        }
        res=max(res,r-R);
    }
    printf("%d\n",res);
    return 0;
}