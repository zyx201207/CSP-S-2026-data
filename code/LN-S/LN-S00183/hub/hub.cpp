#include<bits/stdc++.h>
using namespace std;
vector<int> v[2000010];
int k1,w,dis;
void dfs(int x, int fa, int d){//当前节点,深度
    if(d>dis){
        k1=x;
        dis=d;
    }
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==fa)  continue;
        dfs(v[x][i],x,d+1);
    }
    return ;
}
int sta[2000010],top,is;
void df(int x, int fa, int a){
    sta[++top]=x;
    if(a==x){
        is=1;
        return ;
    }
    for(int i=0;i<v[x].size();i++){
        if(fa==v[x][i])  continue;
        df(v[x][i],x,a);
        if(is==1)  return ;
    }
    sta[top--]=0;
}
bool vis[2000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n,k,x,y;
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,0,0);
        w=k1,dis=0;
        dfs(k1,0,0);
        df(k1,k1,w);
        int l=1,r=n/2;
        while(l<=r){
            int mid=(l+r)/2;
            for(int i=1;i<=n;i++)  vis[i]=0;
            queue<pair<int,int> > q;
            is=0;
            q.push(make_pair(sta[1+mid],0) );
            q.push(make_pair(sta[top-mid],0) );
            q.push(make_pair(sta[k+mid-1],0) );
            while(!q.empty()){
                int x=q.front().first,d=q.front().second;
                q.pop();
                vis[x]=1;
                if(d>mid)  is=1;
                for(int i=0;i<v[x].size();i++){
                    if(!vis[v[x][i]])  q.push(make_pair(v[x][i],d+1) );
                }
            }
            if(is==0){
                r=mid-1;
            }else{//不可行
                l=mid+1;
            }
        }
        printf("%d\n",r+1);
    }
    return 0;
}
