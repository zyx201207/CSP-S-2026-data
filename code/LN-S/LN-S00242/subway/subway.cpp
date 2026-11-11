#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;int vis[1000001][1000001];
    int w[100001],t[1000001],r[100001],a[10000001];
   cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
            cin>>r[i];
            for(int j=1;j<=r[i];j++){
                cin>>a[j]>>r[j];
                vis[i][a[j]]=1;
            }
    }
    while(q--){

        int x,y;
        cin>>x>>y;
        int num=0,cnt=0;
        int ans=w[x]+w[y];
        if(x==y)cout<<0<<endl;
        for(int i=1;i<=n;i++){
            if(vis[i][x]==1){
                num++;
            }if(vis[i][y]==1){
                cnt++;
            }
        }
        if(num==1&&cnt==1||cnt==n){
            for(int i=1;i<=n;i++){
                if(vis[i][x]==1&&vis[i][y]==1){
                    for(int j=1;j<=r[i];j++){
                        if(a[j]==x||a[j]==y)
                            ans+=t[j];
                    }
                }
            }
        }


        cout<<ans<<endl;
    }
    return 0;
}
