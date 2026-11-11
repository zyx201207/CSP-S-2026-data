#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,u,v,dep[1000005],rec[105],ans,f[1000005];
bool vis[1000005];
vector<int>g[1000005];
void dfs(int u,int fa=0){
    dep[u]=dep[fa]+1,f[u]=fa;
    for(auto v:g[u])
        if(v!=fa)
            dfs(v,u);
}
int dfs2(int u,int fa=0){
    int cnt=0;
    if(vis[u]&&!vis[fa])
        cnt++;
    for(auto v:g[u])
        if(v!=fa)
            cnt+=dfs2(v,u);
    return cnt;
}
int dis(int x,int y){
    int cnt=0;
    if(dep[x]<dep[y])
        swap(x,y);
    while(dep[x]>dep[y])
        cnt++,x=f[x];
    while(x!=y)
        cnt+=2,x=f[x],y=f[y];
    return cnt;
}
int pop(int x){
    int cnt=0;
    while(x){
        cnt+=x%2;
        x/=2;
    }
    return cnt;
}
int dfs3(int u,int dis,int fa=0){
    int maxn=0;
    for(auto v:g[u]){
        if(v!=fa)
            maxn=max(maxn,dfs3(v,u));
    }
    if(maxn==dis)
        vis[u]=true,maxn=-1;
    return maxn+1;
}
void dfs4(int u,int dis,int dp,int fa=0){
    if(dp<=dis+1)
        vis[u]=true;
    for(auto v:g[u])
        if(v!=fa)
            dfs4(v,dis,dp+1,u);
}
bool check(int dis){
    for(int i=1;i<=n;i++)
        vis[i]=false;
    dfs3(1,dis);
    int cnt=0,t1=0,t2=0;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cnt++;
            if(!t1)
                t1=i;
            else if(!t2)
                t2=i;
        }
    }
    if(cnt>2)
        return false;
    dfs4(t1,dis,1),dfs4(t2,dis,1);
    for(int i=1;i<=n;i++)
        if(!vis[i])
            return false;
    return true;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        for(int i=1;i<=n;i++)
            g[i].clear();
        ans=0x3f3f3f3f;
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v),g[v].push_back(u);
        }
        dfs(1);
        if(c<=3){
            for(int i=0;i<(1<<n);i++){
                for(int j=1;j<=n;j++)
                    vis[j]=false;
                if(k!=pop(i))
                    continue;
                int tmp=0,sum=0;
                for(int j=1;j<=n;j++)
                    if((i>>(j-1))&1)
                        rec[++tmp]=j,vis[j]=true;
                if(dfs2(1)>2)
                    continue;
                for(int j=1;j<=n;j++){
                    int ttt=0x3f3f3f3f;
                    if((i>>(j-1))%2==0){
                        for(int s=1;s<=k;s++)
                            ttt=min(ttt,dis(j,rec[s]));
                        sum=max(sum,ttt);
                    }
                }
                ans=min(ans,sum);
            }
            printf("%d\n",ans);
        }else if(c==7||c==11||c==12){
                int l=1,r=n;
                while(l<=r){
                    int mid=l+r>>1;
                    if(check(mid))
                        r=mid-1,ans=mid;
                    else
                        l=mid+1;
                }
                printf("%d\n",ans);
            }
    }
    return 0;
}
//3h37min 15pts
