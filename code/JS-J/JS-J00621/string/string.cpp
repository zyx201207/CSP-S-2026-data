#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
long long n,a[maxn],b[maxn];long long pos,mid,ans;
char c[maxn];
#define ub(a,b,x) (upper_bound(a,b,x))
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld %c",&a[i],&c[i]);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    mid=(b[n]%2==0)?b[n]/2:b[n]/2+1;
    for(int i=1;i<=n;i++) if(b[i]>=mid) {pos=i;break;}
    int l=1,r=n;
    pos=ub(b+1,b+n+1,mid)-b-1;
    int p=1;
    while(l<pos&&r>pos){
        l=ub(b+1,b+n+1,p)-b-1,r=ub(b+1,b+n+1,n-p+1)-b-1;
        if(c[l]!=c[r]){
            if(b[l]-p<=(n-p+1)-b[r-1]) ans+=(b[l]-p+1),p=b[l]+1;
            else ans+=(n-p+1)-b[r-1],p+=(n-p+1)-b[r-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}
