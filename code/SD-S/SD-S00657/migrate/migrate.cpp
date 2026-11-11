#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
const int N=5000+10,M=2e6+10,INF=1e18+10;
int c,t;
int n,d;
int a[M];
int dis[N][N];
int f[N][N];
int s[N][N];
int la[N];//上一个不同的 
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n==1){
				cout<<'0'<<'\n';
				continue;
			}
			int x=d/(a[2]-a[1]);
			if(x<2){
				cout<<'0'<<'\n';
				continue;
			}
			cout<<max(0ll,n-x*2+1)<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=n+1;j++){
				dis[i][j]=INF;
				f[i][j]=s[i][j]=0;
			}
			la[i]=n+1;
		}
		if(n==1){
			cout<<0<<'\n';
			continue;
		}
		int r=n;
		for(int i=n-1;i>=1;i--){
			while(a[i]+d<a[r])r--;
			if(r==i)continue;
			for(int j=i+1;j<=r;j++){
				dis[i][j]=1;
				f[i][j]=1;
			}
			for(int j=r+1;j<=n;j++){
				dis[i][j]=dis[r][j]+1;
				int kk=la[j];
				if(kk>=r)kk=i;
				//kk+1到r都是一样的
				f[i][j]=min(3ll,s[kk+1][j]-s[r+1][j]);
				if(f[i][j]==2)ans++;
			}
			for(int j=i+1;j<=n;j++){
				s[i][j]=s[i+1][j]+f[i][j];
			}
			for(int j=r+1;j<=n;j++){
				if(dis[i][j]!=dis[i+1][j]){
					la[j]=i;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
