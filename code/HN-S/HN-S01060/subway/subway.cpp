#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int dis[5005],a[1000005],id[1000005],ans[1000005];
struct mode{
    int k,kk[100005],w[100005];
}unline[505];
struct node{
    int s,t,id;
}qu[1000005];
bool cmp(node x,node y){
    return x.s<y.s;
}
vector<int> stion[25];
void intn(){
    for(int i=1;i<=m;i++) dis[i]=100000009;
}
void dfs(int u,int cnt){
    int len=stion[u].size();
    dis[u]=cnt;
    for(int i=0;i<len;i++){
        int line=stion[u][i];
        int kk[1000005],k=unline[line].k,w[1000005];
        for(int j=1;j<=k;j++){
            kk[j]=unline[line].kk[j];
            w[j]=unline[line].w[j];
        }
        for(int j=1;j<=k;j++){
			int v=kk[j];
            if(v==u) continue;
            if(dis[v]>cnt+w[u]+w[v]){
                dfs(v,dis[v]);
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    //cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		//cin>>a[i];
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&unline[i].k);
        //cin>>unline[i].k;
        for(int j=1;j<=unline[i].k;j++){
            scanf("%d%d",&unline[i].kk[j],&unline[i].w[j]);
            //cin>>unline[i].kk[j]>>unline[i].w[j];
            stion[unline[i].kk[j]].push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].s,&qu[i].t);
        //cin>>qu[i].s>>qu[i].t;
        qu[i].id=i;
    }
    sort(qu+1,qu+q+1,cmp);
    for(int i=1;i<=q;i++){
        if(qu[i].s!=qu[i-1].s){
            intn();
            dis[qu[i].s]=0;
            dfs(qu[i].s,0);
        }
        ans[qu[i].id]=dis[qu[i].t]+a[qu[i].s]+a[qu[i].t];
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
        //cout<<ans[i]<<endl;
    }
    return 0;
}
