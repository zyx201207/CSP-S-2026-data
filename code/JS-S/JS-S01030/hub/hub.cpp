#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,ans,dist[2000010];
vector<int> edges[2000010];
bool b[2000010];
queue<int> q;

void dfs(int i,int j){
    if(j==k){
        while(!q.empty()){
            q.pop();
        }
        memset(dist,127,sizeof(dist));
        for(int l=1;l<=n;l++){
            if(b[l]){
                dist[l]=0;
                q.push(l);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:edges[x]){
                if(dist[y]>dist[x]+1){
                    dist[y]=dist[x]+1;
                    q.push(y);
                }
            }
        }
        int ma=0;
        for(int l=1;l<=n;l++){
            ma=max(ma,dist[l]);
        }
        ans=min(ans,ma);
        return;
    }
    if(i==n+1){
        return;
    }
    b[i]=0;
    dfs(i+1,j);
    b[i]=1;
    dfs(i+1,j+1);
    b[i]=0;
}

int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(;t--;){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        ans=INT_MAX;
        memset(b,0,sizeof(b));
        dfs(1,0);
        printf("%d\n",ans);
    }
}
