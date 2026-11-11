#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,mi,cnt,ans;
long long d,x[2000005];
void dfs(int dep,int u,int e){
    if(u==e){
        if(dep==mi)cnt++;
        else if(dep<mi){
            mi=dep;
            cnt=1;
        }
    }
    for(int v=u+1;v<=e;v++){
        if(x[v]-x[u]>d)break;
        dfs(dep+1,v,e);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        ans=0;
        cin >> n >> d;
        for(int i=1;i<=n;i++)cin >> x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt=1,mi=2000010;
                dfs(1,i,j);
                if(cnt==2)ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
