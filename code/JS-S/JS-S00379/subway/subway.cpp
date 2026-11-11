#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,sum;
int w[1005],o,s,e;
int a[1005][1005],t[1005][1005],cnt[1005];
void dfs(int x,int y,int z){
    if(x==y){
        z+=w[y];
        ans=min(ans,z);
        cout<<ans;
        return;
    }
    cnt[x]++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            if(x==a[i][j]){
                    if(a[i][j+1]&&cnt[a[i][j+1]]==0){
                        dfs(a[i][j+1],y,z);
                    }
                    else if(cnt[a[i][j-1]]==0){
                        dfs(a[i][j-1],y,z);
                    }
            }
        }
       z+=t[i][x];
       return;
}
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)   cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>o;
        for(int j=1;j<=o;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        cin>>s>>e;
        if(s==e){
            cout<<0;
            continue;
        }
        int u=s;
        dfs(u,e,sum);
        cout<<0;
       }
    return 0;
}
