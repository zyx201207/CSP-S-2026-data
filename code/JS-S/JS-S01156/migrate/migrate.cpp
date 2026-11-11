#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;

int c,t,n,minn=INT_MAX;
ll mp[N],d,ans[N],cnt;
bool vis[N];

struct node{
    ll x;
    int step;
};

void bfs(int s,int e){
    queue<node> q;
    q.push({s,0});
    vis[s]=true;
    while(q.size()){
        node u=q.front();
        q.pop();
        if(u.step>minn){
            continue;
        }
        if(mp[u.x]==mp[e]){
            minn=min(minn,u.step);
            ans[u.step]++;
            //vis[u.x]=false;
        }
        for(int i=u.x;i<=n;i++){
            if(!vis[i]){
                if(abs(mp[i]-mp[u.x])<=d){
                    vis[i]=true;
                    q.push({i,u.step+1});
                }
            }
        }
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        cnt=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&mp[i]);
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                bfs(i,j);
                for(int k=1;k<=n;k++){
                    if(ans[k]!=0){
                        if(ans[k]==2){
                            cnt++;
                        }
                        break;
                    }
                }
                for(int k=1;k<=n;k++){
                    cout<<vis[k]<<" ";
                }
                cout<<"\n";
                memset(vis,false,sizeof(vis));
                memset(ans,0,sizeof(ans));
            }
        }
        cout<<cnt<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
