#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int maxn=5e5+1,maxj=501;
long long w[maxn],t;
int a[maxj][maxn],k[maxn],fa[maxn];
vector<int>ve[maxn],vv[maxn];
int find_root(int x){
    return find_root(fa[x]);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) fa[i]=i;
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=2*k[i];j++){
            int u;
            scanf("%d%lld",&u,&t);
            vv[i].push_back(u);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<vv[i].size()-1;j++){
            int v=vv[i][j],t=vv[i][j+1];
            if(find_root(v)!=find_root(t)){
                v=fa[t];
            }
            ve[v][t]=1;
            ve[t][v]=1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(find_root(i)==find_root(j)){
                ve[i][j]=1;
                ve[j][i]=1;
            }else{
                ve[i][j]=ve[find_root(i)][find_root(j)];
                ve[j][i]=ve[find_root(i)][find_root(j)];
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        long long sum=0;
        sum+=w[x];
        sum+=w[y];
        sum+=ve[x][y]*t*2;
        cout<<sum;
    }
    return 0;
}
