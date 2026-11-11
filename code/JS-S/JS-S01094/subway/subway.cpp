#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=500010,N=510;
int c,n,m,d,q;
int w[M],k[N];
vector<int> a[N],t[N];
map<int,vector<int> > num;
map<int,int> anti_a[N];
int g[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        a[i].push_back(1e18);
        t[i].push_back(1e18);
        for(int j=0;j<k[i];j++){
            int x,y;cin>>x>>y;
            num[x].push_back(i);
            anti_a[i][x]=j+1;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                g[i][j]=1e18;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            for(int x=1;x<=k[i];x++){
                int station=a[i][x];
                if(anti_a[j][station]==0)continue;
                else{
                    int t1=t[i][x],t2=t[j][anti_a[j][station]];
                    g[i][j]=min(g[i][j],t1+t2);
                    g[j][i]=min(g[j][i],t1+t2);
                }
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(i==k)continue;
            for(int j=0;j<n;j++){
                if(j==i||j==k)continue;
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(int i=0;i<num[x].size();i++){
            for(int j=0;j<num[y].size();j++){
                int numx=num[x][i];
                int numy=num[y][j];
                ans=min(ans,g[numx][numy]+t[numx][anti_a[numx][x]]+t[numy][anti_a[numy][y]]);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
}
//O(m+m+n*m+n*n*n+q*d*d)<=O(1000000+250000000+125000000+40000000)=O(3*10^8)
