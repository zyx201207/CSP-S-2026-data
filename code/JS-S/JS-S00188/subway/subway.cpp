#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll rote,t;
};
ll w[500010];
vector<node>zhandian[500010];
vector<ll>a[510];
ll asize[510];
ll ans[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            ans[i][j]=90000000000000000;
        }
    }
    for(int i=1;i<=500;i++)ans[i][i]=0;
    ll c,n,m,d,q,x,y;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>asize[i];
        for(int j=1;j<=asize[i];j++){
            cin>>x>>y;
            zhandian[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        if(zhandian[i].size()>=2){
            for(int j=0;j<zhandian[i].size()-1;j++)
            for(int k=j+1;k<=zhandian[i].size();k++){
                ans[zhandian[i][j].rote][zhandian[i][k].rote]=min(ans[zhandian[i][j].rote][zhandian[i][k].rote],zhandian[i][j].t+zhandian[i][k].t);
                ans[zhandian[i][k].rote][zhandian[i][j].rote]=min(ans[zhandian[i][k].rote][zhandian[i][j].rote],zhandian[i][k].t+zhandian[i][j].t);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||j==k||i==k)continue;
                if(ans[i][k]+ans[k][j]<ans[i][j])ans[i][j]=ans[i][k]+ans[k][j];
            }
        }
    }
    ll ot;
    while(q--){
        ot=10000000000000000;
        cin>>x>>y;
        for(int i=0;i<zhandian[x].size();i++){
            for(int j=0;j<zhandian[y].size();j++){
                ot=min(ot,ans[zhandian[x][i].rote][zhandian[y][j].rote]+zhandian[x][i].t+zhandian[y][j].t);
            }
        }
        cout<<(ll)(ot+w[x]+w[y])<<'\n';
    }
    return 0;
}
/* 76min
1、不开ll见祖宗
2、ll不开完全，等于完全不开ll
*/
