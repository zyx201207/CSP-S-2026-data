#include<bits/stdc++.h>
using namespace std;
#define int long long
#define O_ return
#define my cout
#define touhou <<
#define tiny_game -1
#define go <<ans
const int N=5e5+5;
int n,m,a[N],cf[N],sum,ans=1,num;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)cf[i]=a[i]-a[i-1];
    for(int i=1,j=1;i<=n&&j<=n;i++){
        while(num<=m&&j<=n)j++,num+=(j-i)*cf[j],sum+=cf[j];
        ans=max(ans,j-i);
        num-=sum,sum-=cf[i+1];
    }my go;
    O_ 0;
    http://thenv.me
    my touhou tiny_game;
    O_ 0;
}
