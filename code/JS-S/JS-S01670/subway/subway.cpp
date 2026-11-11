#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+510;
int read(){
    int f=1,x=0;
    char ch='\n';
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-') f=-1;
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return f*x;
}
void write(int x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    x%=10;
    putchar(x+'0');
}
vector<pair<int,int> >G[M];
int must[M],ans[M],fa[M][21],deep[M];
int n,m,d,q;
struct Node{
    int fa,dep,val;
    //operator > (Node x) {
    //    return val>x.val;
    //}
};
bool cmp(Node x,Node y){
    return x.val>y.val;
}
void init(){
    vector<Node>pq;
    pq.push_back({0,1,0});
    while(!pq.empty()){
        auto _=pq[pq.size()-1];
        pq.pop_back();
        //cout<<_.fa<<' '<<_.dep<<' '<<_.val<<endl;
        if(ans[_.dep]!=0) continue;
        fa[_.dep][0]=_.fa,deep[_.dep]=deep[_.fa]+1;
        for(int i=1;i<21;i++) fa[_.dep][i]=fa[fa[_.dep][i-1]][i-1];
        ans[_.dep]=_.val;
        //cout<<G[_.dep].size()<<' '<<_.dep<<endl;
        for(auto u:G[_.dep]){
            //cout<<u.first<<' '<<u.second<<endl;
            if(ans[u.first]!=0) continue;
            int va=_.val+u.second;
            pq.push_back({_.dep,u.first,va});
        }
        sort(pq.begin(),pq.end(),[](Node x,Node y){
             return x.val>y.val;
        });
    }
    return;
}
int lca(int x,int y){
    if(deep[x]<deep[y]){
        swap(x,y);
    }
    for(int i=20;i>=0;i--) if(deep[x]-(1<<i)>=deep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    n=read(),n=read(),m=read(),d=read(),q=read();
//    cin>>n>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) must[i]=read();
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        for(int j=1;j<=k;j++){
            int aa,tt;
            aa=read(),tt=read();
            G[aa].push_back({m+i,tt}),G[m+i].push_back({aa,tt});
            //cout<<aa<<' '<<m+i<<endl;
        }
    }
    //for(int i=1;i<=n+m;i++) sort(G[i].begin(),G[i].end(),[](pair<int,int>x,pair<int,int>y){return x.second<y.second;});
    //for(int i=1;i<=n+m;i++) fa[i]=i;
    init();
    //for(int i=1;i<=m+n;i++){
    //    for(int j=0;j<=20;j++) cout<<j<<' '<<fa[i][j]<<"  ";
    //    cout<<endl;
    //}
    while(q--){
        int x,y;
        x=read(),y=read();
        int _lca=lca(x,y);
        write(ans[x]+ans[y]-2*ans[_lca]+must[x]+must[y]);
        putchar('\n');
    }
    return 0;
}
