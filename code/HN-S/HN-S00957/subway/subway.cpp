#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=5e5+5,M=505,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[N],f[M][M];
struct node{int id,val;};
vector<node>v[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,len;i<=n;i++){
        cin>>len;
        for(int j=1,x,y;j<=len;j++)
            cin>>x>>y,v[x].pb({i,y});
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<v[i].size();i++){
            for(int k=j+1;k<v[i].size();k++){
                node x=v[i][j],y=v[i][k];
                f[x.id][y.id]=min(f[x.id][y.id],x.val+y.val);
                f[y.id][x.id]=min(f[y.id][x.id],x.val+y.val);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y,ans=inf;
        cin>>x>>y;
        for(int i=0;i<v[x].size();i++){
            for(int j=0;j<v[y].size();j++){
                node t1=v[x][i],t2=v[y][j];
                ans=min(ans,w[x]+t1.val+w[y]+t2.val+f[t1.id][t2.id]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
