#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sd second
using namespace std;
int c,n,m,d,e,k;
ll w[500005],s[505][505],v[505][505],ans=0,jx,jy,kx,ky,x,y;
vector<pair<ll,ll> > rod[500005];
priority_queue<pair<ll,ll> > q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>e;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            rod[x].push_back({i,y});
        }
        for(int j=1;j<=n;j++){
            v[i][j]=-1;
            s[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<rod[i].size();j++){
            for(int k=0;k<rod[i].size();k++){
                jx=rod[i][j].ft;
                jy=rod[i][j].sd;
                kx=rod[i][k].ft;
                ky=rod[i][k].sd;
                if(v[jx][kx]==-1) v[jx][kx]=jy+ky;
                else v[jx][kx]=min(v[jx][kx],jy+ky);
            }
        }
    }
    for(int i=1;i<=n;i++){
        q.push({0,i});
        while(!q.empty()){
            x=-q.top().ft,y=q.top().sd;
            q.pop();
            if(s[i][y]!=-1) continue ;
            s[i][y]=x;
            for(int k=1;k<=n;k++){
                if(k==y||v[y][k]==-1||s[i][k]!=-1) continue ;
                q.push({-x-v[y][k],k});
            }
        }
    }
    for(int i=1;i<=e;i++){
        cin>>x>>y;
        ans=1e16;
        for(int j=0;j<rod[x].size();j++){
            for(int k=0;k<rod[y].size();k++){
                jx=rod[x][j].ft;
                jy=rod[x][j].sd;
                kx=rod[y][k].ft;
                ky=rod[y][k].sd;
                if(jx==kx) ans=min(ans,ky+jy);
                else ans=min(ans,ky+jy+s[kx][jx]);
            }
        }
        cout<<w[x]+w[y]+ans<<"\n";
    }
    return 0;
}
