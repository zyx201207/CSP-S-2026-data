#include <bits/stdc++.h>
using namespace std;
constexpr int N=600005,M=2000005;
int hd[N],nt[M],to[M],wt[M],cnt=1;
void add(int a,int b,int w){
    nt[cnt]=hd[a];
    hd[a]=cnt;
    to[cnt]=b;
    wt[cnt++]=w;
}
int c,n,m,d,q;
long long w[N];
int fa[N],sz[N];
void init(){
    for (int i=0;i<N;i++){
        fa[i]=i;
        sz[i]=1;
    }
}
int fd(int p){
    int q=p,tmp;
    while (fa[p]!=p)p=fa[p];
    while (fa[q]!=q){tmp=fa[q];fa[q]=p;q=tmp;}
    return p;
}
void uni(int a,int b){
    int p=fd(a),q=fd(b);
    if (p==q)return;
    if (sz[p]>sz[q]){
        fa[q]=p;
        sz[p]+=sz[q];
    }else{
        fa[p]=q;
        sz[q]+=sz[p];
    }
}
int jp[N][20],dep[N];
long long sm[N][20];
void predo(int p,int fa){
    jp[p][0]=fa;
    dep[p]=dep[fa]+1;
    for (int i=hd[p];i;i=nt[i]){
        if (to[i]==fa)continue;
        predo(to[i],p);
        sm[to[i]][0]=wt[i];
    }
}
void inlca(){
    for (int i=1;i<20;i++){
        for (int j=1;j<=m+n;j++){
            jp[j][i]=jp[jp[j][i-1]][i-1];
            sm[j][i]=sm[j][i-1]+sm[jp[j][i-1]][i-1];
        }
    }
}
long long lca(int a,int b){
    long long res=0;
    if (dep[a]<dep[b])swap(a,b);
    for (int i=0;dep[a]!=dep[b];i++){
        if ((dep[a]-dep[b])&(1<<i)){
            res+=sm[a][i];
            a=jp[a][i];
        }
    }
    if (a==b)return res;
    for (int i=19;i>=0;i--){
        if (jp[a][i]!=jp[b][i]){
            res+=sm[a][i]+sm[b][i];
            a=jp[a][i];
            b=jp[b][i];
        }
    }
    return res+sm[a][0]+sm[b][0];
}
int edc=0;
pair<int,pair<int,int>> ed[M];
int main(){
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;
            ed[edc++]={t,{a,i+m}};
//            add(a,i+m,t);
//            add(i+m,a,t);
        }
    }
    sort(ed,ed+edc);
    for (int i=0;i<edc;i++){
        if (fd(ed[i].second.first)!=fd(ed[i].second.second)){
            uni(ed[i].second.first,ed[i].second.second);
            add(ed[i].second.first,ed[i].second.second,ed[i].first);
            add(ed[i].second.second,ed[i].second.first,ed[i].first);
        }
    }
    predo(1,0);
    inlca();
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)+w[a]+w[b]<<'\n';
    }
    return 0;
}
