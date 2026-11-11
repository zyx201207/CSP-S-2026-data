#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
const int N=500005;
int c,t,n,d,a[N];
int dis[N],cnt[N],ans,vis[N];
int main(){
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        ans=0;
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i;k<=j;k++){
                    cnt[k]=1;
                }
                memset(vis,0,sizeof(vis));
                memset(dis,0x3f,sizeof(dis));
                queue<int>q;
                q.push(i);
                dis[i]=0;
                cnt[i]=1;
                while(!q.empty()){
                    int u=q.front();
                    q.pop();
                    if(vis[u])continue;
                    vis[u]=1;
                    for(int k=u+1;k<=j;k++){
                        if(a[k]-a[u]<=d){
                            if(dis[u]+1<dis[k]){
                                dis[k]=dis[u]+1;
                                cnt[k]=cnt[u];
                            }
                            else if(dis[u]+1==dis[k]){
                                cnt[k]+=cnt[u];
                            }
                            q.push(k);
                        }
                        else{
                            break;
                        }
                    }
                }
                // cout << "\n";
                // for(int k=i;k<=j;k++){
                //     cout << cnt[k]<<"|";
                // }
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout << ans;
    }
}