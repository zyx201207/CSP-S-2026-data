#include<bits/stdc++.h>
using namespace std;
const int N=511,D=23,Q=1e5+11;
long long dot,n,m,d,q;
vector<long long>jg[500001];
long long k[N],w[500001],ti[500001][3],a[N][D],t[N][D],f[5001][5001];
long long x[Q],y[Q],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>dot>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(dot==20||dot==21){
		//n==2
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				jg[a[i][j]].push_back(i);
				ti[a[i][j]][i]=t[i][j];
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++)cout<<a[i][j]<<' ';
			cout<<'\n';
		}*/
		long long minn=2e9;
		for(long long i=1;i<=m;i++){
			if((long long)jg[i].size()!=2)continue;
			minn=min(minn,ti[i][1]+ti[i][2]);
		}
		/*cout<<minn<<'\n';
		for(long long i=1;i<=m;i++){
			cout<<jg[i].size()<<'\n';
		}*/
		for(long long i=1;i<=q;i++){
			cin>>x[i]>>y[i];
			ans=1e9;
			for(auto sx:jg[x[i]]){
				for(auto sy:jg[y[i]]){
					if(sx==sy){
						ans=min(ti[x[i]][sx]+ti[y[i]][sy],ans);
					}else{
						ans=min(ans,minn+ti[x[i]][sx]+ti[y[i]][sy]);
					}
				}
			}
			//cout<<ans<<'\n';
			cout<<ans+w[x[i]]+w[y[i]]<<'\n';
		}
		return 0;
	}
	if(dot>=12&&dot<=19){
		//B 32pts
		long long T;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				f[i][j]=1e9;
			}
			f[i][i]=0;
		}
		for(long long i=1;i<=n;i++){
			cin>>k[i];
			for(long long j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				T=t[i][j];
				jg[a[i][j]].push_back(i);
			}
		}
		for(long long i=1;i<=m;i++){
			for(long long j=0;j<(long long)jg[i].size();j++){
				for(long long k=j+1;k<(long long)jg[i].size();k++){
					long long u=jg[i][j],v=jg[i][k];
					f[u][v]=f[v][u]=1;
				}
			}
		}
		for(long long k=1;k<=n;k++){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		/*cout<<T<<'\n';
		return 0;*/
		/*for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				cout<<f[i][j]<<' ';
			}
			cout<<'\n';
		}*/
		//cout<<n<<'\n';
		//q=1;
		for(long long i=1;i<=q;i++){
			cin>>x[i]>>y[i];
			ans=1e9;
			for(auto sx:jg[x[i]]){
				for(auto sy:jg[y[i]]){
					ans=min(ans,f[sx][sy]);
				}
			}
			//cout<<ans<<' '<<T<<' '<<w[x[i]]<<' '<<w[y[i]]<<':'<<x[i]<<','<<y[i]<<'\n';
			cout<<(ans+1)*2*T+w[x[i]]+w[y[i]]<<'\n';
		}
		return 0;
	}
	//#1~11 44pts
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			f[i][j]=1e9;
		}
		f[i][i]=0;
	}
	/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
	*/
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(long long j=1;j<=k[i];j++){
			for(long long p=j+1;p<=k[i];p++){
				f[a[i][p]][a[i][j]]=f[a[i][j]][a[i][p]]=min(f[a[i][j]][a[i][p]],t[i][j]+t[i][p]);
			}
		}
	}
	for(long long k=1;k<=m;k++){
		for(long long i=1;i<=m;i++){
			for(long long j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<w[x[i]]+w[y[i]]+f[x[i]][y[i]]<<'\n';
	}
	return 0;
}
