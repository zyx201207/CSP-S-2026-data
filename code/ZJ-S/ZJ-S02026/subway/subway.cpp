#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505 , M = 5e5+5 ;
struct data{
	int x,t;
};
vector<data>a[M];
int w[M],f[N][N],c,n,m,d,q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(f,0x3f,sizeof(f));
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)cin>>w[i];
	
	//5e5
	int k,x,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>t;
			a[x].push_back({i,t});
		}
		f[i][i]=0;
	}
	
	//5e7
	int x1,x2,t1,t2;
	for(int i=1;i<=m;i++){
		for(int u=0;u<a[i].size()-1;u++){
			for(int v=u+1;v<a[i].size();v++){
				x1=a[i][u].x;
				x2=a[i][v].x;
				t1=a[i][u].t;
				t2=a[i][v].t;
				f[x1][x2]=f[x2][x1]=min(f[x1][x2],t1+t2);
			}
		}
	}
	
	//floyd  1.25e8
	for(int k=1;k<=n;k++){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	//4e7
	int y,ans;
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				ans=min(ans,a[x][i].t+a[y][j].t+f[a[x][i].x][a[y][j].x]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}