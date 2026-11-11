#include<bits/stdc++.h>
using namespace std;
long long c,t;long long n,d;long long a[200006];int mx[50006][50006];bool vis[200006];int cnt[50006][50006];
void dfs(int u,int sum){for(int i=1;i<=n;i++){
        if(a[max(u,i)]-a[min(u,i)]>d&&vis[i]==0){
            vis[i]=1;
            mx[u][i]=min(sum+1,mx[u][i]);
            dfs(i,sum+1);
            vis[i]=0;
        }
    }
}
void dfs2(int u,int sum){
    for(int i=1;i<=n;i++){
        if(a[max(u,i)]-a[min(u,i)]>d&&vis[i]==0){
            vis[i]=1;
            if(sum+1==mx[u][i]){
                cnt[u][i]++;
            }
            dfs(i,sum+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }int ans=0;for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){
            }
        }for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis))dfs(i,0);
        }for(int i=1;i<=n;i++){memset(vis,0,sizeof(vis));dfs2(i,0);
        }
        for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){if(i==j){continue;
                }if(cnt[i][j]==2){}
                ans++;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
