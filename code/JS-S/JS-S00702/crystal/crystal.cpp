#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define ls p<<1
#define rs p<<1|1
#define rst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define int long long
#define btp __builtin_popcount
using namespace std;

const int N(5e5+5);

int n,m,ans,a[N];

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,j=1,s=0;i<=n;i++){
        s+=a[i];
        while((i-j+1)*a[i]-s>m) s-=a[j++];
        cmax(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}