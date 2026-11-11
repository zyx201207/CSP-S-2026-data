#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,res,ans;
long long m,a[N],cost;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    res=1;
    for(int i=2;i<=n;++i){
        cost=cost+res*(a[i]-a[i-1]);
        //cerr<<i<<' '<<cost<<endl;
        while(cost>m)cost-=a[i]-a[i-res],--res;
        ++res,ans=max(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}
//Many years after I graduated, in the mild light of sunset, I recalled a moment when I secretly wrote down this sentence, exactly, the sentence of my distant childhood...
