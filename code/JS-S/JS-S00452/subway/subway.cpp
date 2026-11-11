#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q;
long long w[N];
struct node{
    int v,ww;
};
int ac[N],t[N];
vector<node>ti[N];
int inqueue[N];
int nmin[N];
int spfa(int x,int y){
    memset(nmin,0x3f,sizeof(nmin));
    queue<int>q;
    q.push(x);
    nmin[x]=0;
    while(!q.empty()){
        int u=q.front();
        inqueue[u]=0;
        q.pop();
        for(auto x:ti[u]){
            int v=x.v;
            if(inqueue[v]==1) continue;
            int w=x.ww;
            if(nmin[v]>nmin[u]+w){
                nmin[v]=nmin[u]+w;
                q.push(v);
                inqueue[v]=1;
            }
        }
    }
    return nmin[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i =1;i<=m;i++){
        cin>>w[i];
    }
    for(int i =1;i<=n;i++){
        int q;
        cin>>q;
        memset(ac,0,sizeof(ac));
        memset(t,0,sizeof(t));
        for(int j =1;j<=q;j++){
            int aa,tm;
            cin>>aa>>tm;
            ac[j]=aa;
            t[aa]=tm;
        }
        for(int j=1;j<q;j++){
            for(int r=j+1;r<=q;r++){
                ti[ac[r]].push_back({ac[j],t[ac[r]]+t[ac[j]]});
                ti[ac[j]].push_back({ac[r],t[ac[r]]+t[ac[j]]});
            }
        }
    }

    int x,y;
    for(int i =1;i<=n;i++){
        cin>>x>>y;
        cout<<spfa(x,y)+w[x]+w[y]<<"\n";
    }
    return 0;
}
