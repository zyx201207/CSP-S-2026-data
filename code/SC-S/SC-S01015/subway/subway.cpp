#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
const int N=1e7+5;
long long s[N];
long long a[505][10005];
long long f[505][505];
const long long INF = 1e9+5;
void solve(long long x,long long y){
	long long ans=INF;
	queue<long long> q;
	queue<long long> p;
	for(int i=1;i<=n;i++){
		if(a[i][x]){
			q.push(i);
		}
		if(a[i][y]){
			p.push(i);
		}
	}
	while(!q.empty()){
		long long start=q.front();
		while(!p.empty()){
			long long end=p.front();
			ans=min(f[start][end],ans);
			p.pop();
		}
		q.pop();
	}
	ans+=s[x];
	ans+=s[y];
	cout<<ans<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;

	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i][x]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				for(int t=1;t<=m;t++){
					if(i==k){
						f[i][k]=min(f[i][k],a[i][j]+a[k][t]);
						f[k][i]=f[i][k];
					}
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][i]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}