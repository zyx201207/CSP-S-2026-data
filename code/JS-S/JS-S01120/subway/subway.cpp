#include<bits/stdc++.h>
using namespace std;
const long long M=100000000000000008;
struct node{
    long long a,t;
}a1,a2;
long long c,n,m,d,q;
int w[500005];
int k[505],a,t;
vector<node>ln[505];
vector<node> st[500005];
int x,y;
long long ans,tr[505][505];//ans=w[x1]+w[x2]+t[x1]+t[x2]+min(t[x1][x2])
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i!=j)tr[i][j]=M;
            else tr[i][j]=0;
        }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a,&t);
            ln[i].push_back({a,t});
            st[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<st[i].size();j++)
            for(int k=j+1;k<st[i].size();k++){
                a1=st[i][j],a2=st[i][k];
                tr[a1.a][a2.a]=min(a1.t+a2.t,tr[a1.a][a2.a]);
                tr[a2.a][a1.a]=tr[a1.a][a2.a];
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
            tr[i][j]=min(tr[i][j],tr[i][k]+tr[k][j]);
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        ans=M;

        for(int j=0;j<st[x].size();j++)
            for(int k=0;k<st[y].size();k++){
                ans=min(ans,st[x][j].t+st[y][k].t+tr[st[x][j].a][st[y][k].a]);
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
}
//add long long !!!
