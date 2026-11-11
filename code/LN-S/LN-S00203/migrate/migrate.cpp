#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,f=0,n,d,mis=1e14;
int a[2000010];
unordered_map<int,int>mp;
void dfs(int u,int v,int step){
    if(u==v){
        if(step<mis){
            mis=step;
        }
        mp[step]++;
        return;
    }
    for(int j=u+1;j<=v;j++){
        if(a[j]-a[u]<=d){
            dfs(j,v,step+1);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                mp.clear();
                mis=1e14;
                dfs(i,j,0);
                if(mp[mis]==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
