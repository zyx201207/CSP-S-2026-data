#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int c,t,n,d,a[N],cnt,cc,mins;

bool vis[N];

void dfs(int x,int u,int v,int sum){
    if(x==v){
        if(sum==mins) c++;
        else if(sum<mins){
            c=1;
            mins=sum;
            return;
        }else return;
        return;
    }
    for(int i=x+1;i<=n;i++){
        if(!vis[i]&&a[x]+d>=a[i]){
            vis[i]=1;
            dfs(i,u,v,a[x]+d-a[i]);
            vis[i]=0;
        }
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        cnt=0;cc=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    mins=INT_MAX;
                cc=0;
                dfs(i,i,j,0);
                if(c>=2) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
