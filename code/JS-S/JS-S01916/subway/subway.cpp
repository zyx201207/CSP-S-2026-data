#include<bits/stdc++.h>
using namespace std;
struct T{
    int id,ti;
}k[5000][410];
vector<T> ma[500];
int c,n,m,d,q,kk[5000];
int a[500],sa[5000][410],bo[500];
int solve(int u,int v,int nl,int step){
    if(u==v) return a[u]+sa[nl][v];
    int res=1e9;
    for(T i:ma[u]){
        bo[u]=1;
        for(int j=1;j<=kk[i.id];j++){
            int cost=sa[nl][u];
            if(nl!=i.id) {
                cost=i.ti+sa[nl][u];
            }
            if(!bo[k[i.id][j].id]) res=min(res,solve(k[i.id][j].id,v,i.id,step+1)+cost);
        }
        bo[u]=0;
    }
    return res;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>kk[i];
        for(int j=1;j<=kk[i];j++){
            cin>>k[i][j].id>>k[i][j].ti;
            sa[i][k[i][j].id]=k[i][j].ti;
            ma[k[i][j].id].push_back({i,k[i][j].ti});
        }
    }
    while(q--){
        int uu,vv;
        cin>>uu>>vv;
        memset(bo,0,sizeof(bo));
        int minn=1e9;
        for(T i:ma[uu]){
            memset(bo,0,sizeof(bo));
            minn=min(minn,solve(uu,vv,i.id,0)+a[uu]);
        }
        cout<<minn<<endl;
    }
    return 0;
}