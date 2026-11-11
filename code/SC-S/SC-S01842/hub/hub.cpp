#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<queue>
#define N 1000005
int n,k,d1[N],d2[N],zh1,zh2,ans;
std::vector<int>G[N];
void dfs1(int now,int fa){
    d1[now]=d1[fa]+1;
    for(int i:G[now])if(i-fa)dfs1(i,now);
}
void dfs2(int now,int fa){
    d2[now]=d2[fa]+1;
    for(int i:G[now])if(i-fa)dfs2(i,now);
}
int sumn,CID,p[N];
void dfs3(int now,int fa){
    p[now]=fa;
    for(int i:G[now])if(i-fa)dfs3(i,now);
}
int cnt,d[N];
std::vector<int>lst,cur;
void solve(int a,int b){
    // printf("(%d %d)",a,b);
    cnt=n,cur.clear();
    for(int i=1;i<=n;i++)d[i]=G[i].size()-(i==a)-(i==b);
    for(int i=1;i<=n;i++)if(d[i]==1)cur.push_back(i);
    for(int t=0;t<n;t++){
        if(cnt<=k)return /*printf("%d %d %d\n",a,b,t),*/ans=std::min(ans,t),void();
        lst=cur,cur.clear(),cnt-=lst.size();//printf("[%d %d]",t,cnt);
        for(int i:lst){
            d[i]=0;
            for(int j:G[i])if((i!=a||j!=b)&&(i!=b||j!=a)){
                if(d[j]==1)cnt++;//printf("(%d)",j);
            }
        }
        for(int i:lst){
            for(int j:G[i])if((i!=a||j!=b)&&(i!=b||j!=a)){
                if(d[j]>1){
                    d[j]--;
                    if(d[j]==1)cur.push_back(j);
                }
            }
        }
    }
}
std::pair<int,int>P[N];
void Main(){
    scanf("%d%d",&n,&k),ans=n,sumn+=n;
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(CID<=10){
        for(int i=1;i<=n;i++)for(int j:G[i])if(j<i)solve(j,i);
    }
    else{
        zh1=zh2=0;
        dfs1(1,0);
        for(int i=1;i<=n;i++)if(d1[i]>d1[zh1])zh1=i;
        dfs2(zh1,0);
        for(int i=1;i<=n;i++)if(d2[i]>d2[zh2])zh2=i;
        dfs1(zh2,0);
        int rt=1;
        for(int i=1;i<=n;i++)if(d1[i]==(d2[zh2]+1)/2&&d2[i]==(d2[zh2]+1-(d2[zh2]+1)/2))rt=i;
        for(int i:G[rt])if(d1[i]+d2[i]==d2[zh2]+1)solve(rt,i);
        dfs1(rt,0),dfs3(rt,0);
        for(int i=1;i<=n;i++)P[i]={d1[i],i};
        std::sort(P+1,P+n+1);
        if(CID<=14)for(int i=2;i<=200&&i<=n;i++)solve(P[i].second,p[P[i].second]);
        else if(CID<=17)for(int i=2;i<=100&&i<=n;i++)solve(P[i].second,p[P[i].second]);
        else for(int i=2;i<=50&&i<=n;i++)solve(P[i].second,p[P[i].second]);
    }
    printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;
    scanf("%d%d",&CID,&t);
    while(t--)Main();
}