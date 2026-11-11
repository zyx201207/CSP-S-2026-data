#include<bits/stdc++.h>
const int M=5e5+5,N=5e2+5;
using namespace std;
int n,m,d,q,c;
int w[M],k[N],a[N][M],t[N][M];
int dist[M];
int ans=0;
vector<long long> g[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        cin>>a[i][1]>>t[i][1];
        for(int j=2;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            g[a[i][j-1]].push_back(a[i][j]);
            g[a[i][j]].push_back(a[i][j-1]);
        }
    }
    for(int s=1;s<=q;s++){
        int x,y;
        cin>>x>>y;
        int xi=0x3f3f3f3f,yi=0x3f3f3f3f,x1,x2,y1,y2;
        for(int i=1;i<=n;i++){

            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    xi=min(xi,t[i][j]);
                    if(xi==t[i][j]){
                        x1=i;
                        x2=j;
                    }
                }
                if(a[i][j]==y){
                    yi=min(yi,t[i][j]);
                    if(yi==t[i][j]){
                        y1=i;
                        y2=j;
                    }
                }
            }
        }
        cout<<w[x]+t[x1][x2]+t[y1][y2]+w[y]<<endl;
    }
    return 0;
}
