#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int n,m,a[maxn],ans=-1;
void dfs(int now,int num,int sum,int fa){
    if(sum<=ans) return;
    if(num+(n-now+1)<m) return;
    if(num==m+1){if(sum>ans) ans=sum;return;}
    //cout<<now<<" "<<sum<<" "<<num<<endl;
    for(int i=now;i<=n;i++){
        if(i==fa) continue;
        dfs(i,num+1,sum&a[i],now);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dfs(1,0,(1<<30)-1,0);
    cout<<ans<<endl;
    return 0;
}
