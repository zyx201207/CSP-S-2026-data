#include<bits/stdc++.h>
using namespace std;
const int N=507,M=5e5+7;
int _,n,m,d,q;
int w[M];
int ans=INT_MAX;
#define pb push_back
#define fi first
#define se second
//vector< pair<int,int> > v[N];
int k[N];
bool vis[1007];
int yy[1007];
pair<int,int> a[1007][22];
void dfs(bool yty[1007],int x,int pos,int val){
    if(pos==x){
        ans=min(ans,val);
        return;
    }
    for(int i=1;i<=yy[x];i++){
        if(yty[a[x][i].first])continue;
        yty[a[x][i].first]=1;
        dfs(yty,a[x][i].first,pos,val+a[x][i].second);
        yty[a[x][i].first]=0;
    }
    return;
}
pair<int,int> yt[407][201],lx[407][22];
int ly[407],len[407];
void ddfs(bool yty[1007],int x,int pos,int val){
    //cout<<x<<' '<<pos<<' '<<val<<'\n';
    if(x==pos){
        ans=min(ans,val);
        return;
    }
    for(int j=1;j<=ly[x];j++){
        int tmp=lx[x][j].fi;
        int nval=val+lx[x][j].se;
        for(int i=1;i<=len[tmp];i++){
            if(yty[yt[tmp][i].fi])continue;
            yty[yt[tmp][i].fi]=1;
            ddfs(yty,yt[tmp][i].fi,pos,nval+yt[tmp][i].se);
            yty[yt[tmp][i].fi]=0;
        }
    }
    return;
}
main(){
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>_>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){cin>>w[i];}
    if(7<=_&&_<=11){
        for(int i=1;i<=n;i++){
            int kk;cin>>kk;
            int u,v,uu,vv;
            cin>>u>>v>>uu>>vv;
            a[u][++yy[u]].fi=uu,
            a[u][yy[u]].se=v+vv,
            a[uu][++yy[uu]].fi=u,
            a[uu][yy[uu]].fi=v+vv;
        }
        while(q--){
            int l,r;
            ans=INT_MAX;
            cin>>l>>r;
            memset(vis,0,sizeof(0));
            vis[l]=1;
            dfs(vis,l,r,0);
            cout<<ans+w[l]+w[r]<<'\n';
        }
        return 0;
    }
    if(_<=8){
        for(int j=1;j<=n;j++){
            int kk;cin>>kk;len[j]=kk;
            for(int i=1;i<=kk;i++){
                int xx,zz;cin>>xx>>zz;
                yt[j][i].fi=xx,yt[j][i].se=zz;
                lx[xx][++ly[xx]].fi=j;
                lx[xx][ly[xx]].se=zz;
            }
        }
        //for(int i=1;i<=m;i++)for(int j=1;j<=ly[i];j++)cout<<i<<' '<<lx[i][j].fi<<' '<<lx[i][j].se<<'\n';
        while(q--){
            int l,r;
            ans=INT_MAX;
            cin>>l>>r;
            memset(vis,0,sizeof(vis));
            ddfs(vis,l,r,0);
            cout<<ans+w[l]+w[r]<<'\n';
        }
    }
}
