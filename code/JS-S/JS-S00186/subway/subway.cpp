#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int c,n,m,d,q;
int w[N],dis[505][505];
vector<int> xl[N];
vector<int> xlw[N];


signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(dis,0x3f,sizeof dis);
    for(int x=1;x<=n;x++){
        int k;cin>>k;
        vector<int> ls(k+1);
        for(int i=1;i<=k;i++){
            int a,t;cin>>a>>t;
            ls[i]=a;
            xl[a].push_back(x);
            xlw[a].push_back(t);
            for(int j=0;j<xl[a].size()-1;j++){
                dis[xl[a][j]][x]=min(dis[xl[a][j]][x],xlw[a][j]+t);
                dis[x][xl[a][j]]=dis[xl[a][j]][x];
            }
            // if(i>1)dis[ls[i]][ls[i-1]]=dis[ls[i-1]][ls[i]]=0;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(k!=i&&i!=j&&k!=j){
                    dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
                }
            }
        }
    }

    while(q--){
        int x,y;cin>>x>>y;
        int ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<xl[x].size();i++){
            for(int j=0;j<xl[y].size();j++){
                int a=xl[x][i],b=xl[y][j];
                int aw=xlw[x][i],bw=xlw[y][j];
                int now=0;
                if(a==b){
                    now=w[x]+w[y]+aw+bw;
                }else{
                    now=w[x]+w[y]+aw+bw+dis[a][b];
                }
                ans=min(ans,now);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}