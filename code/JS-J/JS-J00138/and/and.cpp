#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
int n,m,a[MAXN],ans;
void dfs(int pos,int val,int cho){
    if(pos>n){
        if(cho==m)
            ans=max(ans,val);
        return ;
    }
    if(n-pos+1<m-cho)return ;
    if(cho<m){
        if(cho==0)
            dfs(pos+1,a[pos],cho+1);
        else 
            dfs(pos+1,val&a[pos],cho+1);
    }
    dfs(pos+1,val,cho);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",a+i);
    dfs(1,0,0);
    printf("%lld\n",ans);
    return 0;
}
// zhe dao ti mei you zui you jie zi jie gou , wo hai xiang yong bei bao zuo 50 ne!