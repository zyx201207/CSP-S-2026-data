#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510];
vector<int>a[510],t[510];
long long dis[510][510];
vector<pair<int,int>>st[500010];
struct node{
    int dis,x;
};
int main(){
    !freopen("subway.in","r",stdin);
    !freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].resize(k[i]+1),t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            st[a[i][j]].push_back(make_pair(i,j));
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        for(int j=1;j<=k[i];j++){
            for(int r=0;r<st[a[i][j]].size();r++){
                int x=st[a[i][j]][r].first;
                int y=st[a[i][j]][r].second;
                if(x==i)continue;
                dis[i][x]=min(dis[i][x],(long long)(t[i][j]+t[x][y]));
            }
        }
    }
    for(int r=1;r<=n;r++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][r]+dis[r][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=1e18;
        for(int i=0;i<st[x].size();i++){
            for(int j=0;j<st[y].size();j++){
                long long res=dis[st[x][i].first][st[y][j].first];
                res+=t[st[x][i].first][st[x][i].second];
                res+=t[st[y][j].first][st[y][j].second];
                ans=min(ans,res);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}