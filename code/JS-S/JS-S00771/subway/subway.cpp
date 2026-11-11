#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int c,n,m,d,q,l[N],w[N],dis[N][N],tail[N];
bool added[N];
//vector<int>a[N],t[N];
int a[N][N],t[N][N];
struct node{
    int v,w,id;
    node(int a,int b,int c){
        v=a,w=b,id=c;
    }
};
vector<node>g[N];
struct shu{
    int pos,bel;
    //friend bool operator<(shu a,shu b){
    //    return a.bel<b.bel;
    //}
};
//set<shu>st[N];
//vector<shu>st[N];
shu st[N][N];
int top[N];
/*
void kruskal(){

}
*/
bool vis[N][N];
int res;
void dfs(int k,int u,int ed,int d){
    if(u==0 || k==0)return ;
    //cerr<<k<<" "<<u<<" "<<ed<<" "<<d<<'\n';
    if(a[k][u]==ed){
        res=min(res,d+t[k][u]);return ;
    }
    if(u==l[k]){return ;
    }
    if(vis[k][u])return ;
    vis[k][u]=1;
    for(int i=u+1;i<=l[k];i++){
        dfs(k,i,ed,d);
    }
    if(top[a[k][u]]>1){
        for(int i=1;i<=top[a[k][u]];i++){
            if(st[a[k][u]][i].bel!=k){
                int x=st[a[k][u]][i].bel;
                auto b=st[a[k][u]][i].pos;
                //int x=k,y=u;
                //cerr<<t[x][y]<<" ";
                //cerr<<t[a][b]<<" ";
                int tmp=d+t[k][u]+t[x][b];
                dfs(x,b,ed,tmp);
                //dfs(a,a,t,a);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",w+i);
    }
    bool ksmaller=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",l+i);
        if(l[i]>2){
            ksmaller=0;
        }
        /*
        a[i].assign(l[i]+1,0);
        t[i].assign(l[i]+1,0);
        */
        for(int j=1;j<=l[i];j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            if(j>1){
                //cerr<<"i: "<<i<<" j: "<<j<<'\n';
                g[a[i][j-1]].push_back(node(a[i][j],t[i][j-1],i));
            }
            st[a[i][j]][++top[a[i][j]]]={j,i};
            tail[a[i][j]]=t[i][j];
            //cerr<<a[i][j]<<" "<<t[i][j]<<'\n';
        }
        //cerr<<i<<" "<<n<<'\n';
    }
    //cerr<<"i'm alive\n";
    if(ksmaller){
        for(int i=1;i<=m;i++){
            //cerr<<"i: "<<i<<'\n';
            for(auto j:g[i]){
                int ID=j.id,W;
                if(top[j.v]>1){
                    for(auto k:g[j.v]){
                        if(k.id==j.id){
                            W=k.w;break;
                        }
                    }
                    for(auto &k:g[j.v]){
                        if(!added[k.v] && k.id!=ID){
                            added[k.v]=1;
                            k.w+=W;
                        }
                    }
                }
            }
        }
        int l,r;
        while(q--){
            scanf("%lld%lld",&l,&r);
            //cerr<<q<<'\n';
            if(l>r){
                swap(l,r);
            }
            if(dis[l][r]){
                int mn=1e18;
                if(g[r].size()>1){
                    for(auto it:g[r]){
                        mn=min(mn,it.w);
                    }
                } else{
                    mn=tail[r];
                }
                printf("%lld\n",w[l]+w[r]+mn+dis[l][r]);continue;
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
            q.push({0,l});
            for(int i=1;i<=m;i++)dis[l][i]=1e18;
            dis[l][l]=0;
            while(!q.empty()){
                int d=q.top().first,u=q.top().second;
                q.pop();
                for(auto it:g[u]){
                    int v=it.v,w=it.w;
                    if(dis[l][v]>dis[l][u]+w){
                        dis[l][v]=dis[l][u]+w;
                        q.push({dis[l][v],v});
                    }
                }
            }
            int mn=1e18;
            if(g[r].size()>1){
                for(auto it:g[r]){
                    mn=min(mn,it.w);
                }
            } else{
                mn=tail[r];
            }
            printf("%lld\n",dis[l][r]+w[l]+w[r]+mn);
        }
        exit(0);
    }
/*
    for(int i=1;i<=m;i++){
        for(int j=1;j<=top[i];j++){
            cerr<<st[i][j].bel<<" "<<st[i][j].pos<<'\n';
        }
    }
*/
    int l,r;
    while(q--){
        scanf("%lld%lld",&l,&r);
        //k u t d
        int ans=1e18,A=1e18;
        for(int i=1;i<=top[l];i++){
            res=1e18;
            //cerr<<"i: "<<i<<" top: "<<top[l]<<'\n';
            memset(vis,0,sizeof vis);
            dfs(st[l][i].bel,st[l][i].pos,r,0);
            ans=min(ans,res);
            //cerr<<"i: "<<i<<" res: "<<res<<" ans: "<<ans<<'\n';
            A=min(A,ans+t[st[l][i].bel][st[l][i].pos]);
        }
        printf("%lld\n",A+w[l]+w[r]);
    }

}
/*
0 3 2 20 1
1 1 1
2 1 1 2 1
3 2 1 1 1 3 1
1 3

*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6

2 3

*/
//made jiale!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

