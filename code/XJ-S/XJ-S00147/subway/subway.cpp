#include<bits/stdc++.h>
using namespace std;
const int N=2e4+2;
int mapp[N][N];
int w[N],a[500+2][N],t[500+2][N];
int c,n,m,d,q,x,y;
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //输入
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++) {
            if(i!=j) {
                mapp[i][j]=0x3f3f3f3f;
            }

        }
    }
    //cout<<mapp[2][1]<<"\n";
    for(int i=1;i<=m;i++) { //地铁口->站厅 时间
        cin>>w[i];
    }
    for(int i=1;i<=n;i++) { //i:第i辆列车
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) { //j,k:站台
            cin>>a[i][j]>>t[i][j];
            int u=a[i][j];
        	int val_u=t[i][j];
            for(int k=j-1;k>=1;k--) {
            	int v=a[i][k];
            	int val_v=t[i][k];
                mapp[u][v]=min(mapp[u][v],val_u+val_v);
            	mapp[v][u]=min(mapp[v][u],val_u+val_v);
            	//printf("%d %d %d %d\n",u,v,mapp[u][v],mapp[v][u]);
            }
        }
    }
    for(int k=1;k<=m;k++) {
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=m;j++) {
                if(i==j||i==k||j==k) continue;
                mapp[i][j]=min(mapp[i][j],mapp[i][k]+mapp[k][j]);
                //printf("%d %d %d %d\n",i,k,j,mapp[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++) {
        cin>>x>>y;
        cout<<w[x]+w[y]+mapp[x][y]<<"\n";
    }
    return 0;
}
