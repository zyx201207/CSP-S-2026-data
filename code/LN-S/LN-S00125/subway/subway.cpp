#include<bits/stdc++.h>
using namespace std;
/*
1-m zhanting
m+1-m+n zhantai
*/
int m,n,c,d,q;
int w[500010];
struct eg{
    int t,l;
};
struct qu{
    int x,y,id;
}g[100010];
long long an[100010];
long long ds[510000];
bool b[510000];
vector<eg> v[510000];
void ad(int x,int y,int l){
    v[x].push_back({y,l});
}
bool cmp(qu x,qu y){
    return x.x<x.y;
}
priority_queue<pair<long long,int> >pq;
void bfs(int f){
    memset(ds,0x3f,sizeof(ds));
    memset(b,0,sizeof(b));
    ds[f]=0;
    pq.push({0,f});
    while(!pq.empty()){
        int x=pq.top().second;
        pq.pop();
        if(b[x]) continue;
        b[x]=1;
        for(eg s:v[x]){
            int t=s.t,l=s.l;
            if(ds[x]+l<ds[t]){
                ds[t]=ds[x]+l;
                pq.push({-ds[t],t});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int ai,ti;
            scanf("%d%d",&ai,&ti);
            ad(i+m,ai,ti);
            ad(ai,i+m,ti);
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&g[i].x,&g[i].y);
        if(g[i].x>g[i].y)swap(g[i].x,g[i].y);
        g[i].id=i;
    }
    sort(g+1,g+q+1,cmp);
    for(int i=1;i<=q;i++){
        if(i==1||g[i].x!=g[i-1].x) bfs(g[i].x);
        an[g[i].id]=ds[g[i].y]+w[g[i].x]+w[g[i].y];
    }
    for(int i=1;i<=q;i++) printf("%lld\n",an[i]);
    return 0;
}
