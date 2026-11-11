#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
long long g[5007],ct[5007],a[5007],n,d;
void dfs(int x){
    if(x==n) return;
    for(int i=x+1;i<=n;++i){
        if(a[i]-a[x]<=d){
            if(g[i]==0) g[i]=g[x]+1,ct[i]=1,dfs(i);
            else{
                if(g[x]+1<g[i]) g[i]=g[x]+1,ct[i]=1,dfs(i);
                else if(g[x]+1==g[i]) ++ct[i],dfs(i);

            }
        }else break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int sum=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        for(int i=1;i<=n;++i){
                dfs(i);
        for(int j=1;j<=n;++j)
                if(ct[j]==2) ++sum;
            memset(g,0,sizeof g);
            memset(ct,0,sizeof ct);
        }
        cout<<sum<<endl;
    }
    return 0;
}
