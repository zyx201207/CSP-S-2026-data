#include <bits/stdc++.h>
//#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
#define pair<int,int> pii
using namespace std;
const int MAXN=50005;
struct node{
    int a,t;
}dot[MAXN][505];
int c,d,q,m,n,w[MAXN],edge[5005][5005],cnt[MAXN],t[MAXN][505];//n is num of dot
bool lin[MAXN][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=5000;i++){
        for(int j=1;j<=5000;j++){
            if(i==j) edge[i][j]=0;
            else edge[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,dt;
            cin>>a>>dt;
            t[a][i]=dt;
            lin[a][i]=1;
            dot[a][++cnt[a]]={i,t[a][i]};
        }
    }
    int ctdot=0;
    for(int i=1;i<=m;i++){
        if(cnt[i]>1){
            ctdot++;
            for(int j=1;j<=cnt[i];j++){
                for(int k=j+1;k<=cnt[i];k++){
                    int u=dot[i][j].a,v=dot[i][k].a,w=dot[i][j].t+dot[i][k].t;
                    edge[u][v]=w;edge[v][u]=w;
                    //cout<<u<<" "<<v<<" "<<w<<endl;
                }
            }
        }
    }
    for(int k=1;k<=ctdot;k++){
        for(int i=1;i<=ctdot;i++){
            for(int j=1;j<=ctdot;j++){
                edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
            }
        }
    }
    while(q--){
        int x,y,px,py,edis=inf;
        cin>>x>>y;
        bool ft=0;
        for(int j=1;j<=n;j++){
            if(lin[x][j]==1 && lin[y][j]==1)
            {
                px=py=j,ft=1;
                break;
            }
            if(lin[x][j]==1){
                for(int k=1;k<=n;k++){
                    if(lin[y][k]==1){
                        edis=min(edis,edge[j][k]);
                        px=j,py=k;
                    }
                }
            }
        }
        if(ft) cout<<w[x]+w[y]+t[x][px]+t[y][py]<<endl;
        else cout<<edis+w[x]+w[y]+t[x][px]+t[y][py]<<endl;
    }
    return 0;
}


//id:JS-S00335
//This is the test file.
//Last modified on Oct.31st 18:21
//?? pts
//1,2 samples are correct
//O(??)
//password:Oct31==Dec25?
//Are you with me? Is it fiction?
//I have lost some points in the 2026 CSP-J test.
//But I will not lose this time.
//I want S 1=,
//And the chance to NOIP(2026.11.28).
//My journey of OI will never fade,
//My love for OI will remain forever,
//And I'm going on a brighter road.

//And now,
//Let's focus on the first problem.
//And I must get this 100 points.
