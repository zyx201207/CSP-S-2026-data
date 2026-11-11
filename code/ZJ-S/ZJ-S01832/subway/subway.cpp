#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+20;
int c,n,m,d,q,k,u,v;
int id,t;
int w[N],ct[N];
struct node{
	int id,t;
};
node z[N][22];
vector<int>a[1005];
int f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int pt=m+i;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>id>>t;
			ct[id]++;
			int yy=ct[id];
			z[id][yy]=(node){pt,t};
		}
	} 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=ct[i];j++){
			for(int k=1;k<=ct[i];k++){
				    if(j==k)continue;
				    int t=z[i][j].t+z[i][k].t;
				    int x=z[i][j].id,y=z[i][k].id;
			        f[x-m][y-m]=f[y-m][x-m]=t;
			    }
	        }
	    }
	    for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(f[i][j]==0)f[i][j]=1e18;
		    }
	    }
	    for(int i=1;i<=n;i++)f[i][i]=0;
	    for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    for(int k=1;k<=n;k++){
				    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			    }
		    }
	    }
	    for(int i=1;i<=q;i++){
		    cin>>u>>v;
		    int minn=1e18;
            for(int j=1;j<=ct[u];j++){
        	    for(int k=1;k<=ct[v];k++){
        		    int x=z[u][j].id,y=z[v][k].id;
        		    minn=min(minn,f[x-m][y-m]+z[u][j].t+z[v][k].t);
			    }
		    }
		    cout<<minn+w[u]+w[v]<<"\n";
	    }
}
