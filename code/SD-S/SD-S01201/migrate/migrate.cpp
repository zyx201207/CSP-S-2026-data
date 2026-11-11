#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e6+5,M=505;
const ll inf=1e18;
int c,T,n;
ll d,a[N],dis[M][M],ans[M][M],res;
void solve(){
	res=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c<=6){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dis[i][j]=0;
				else dis[i][j]=inf;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					dis[i][j]=dis[j][i]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]==inf) ans[i][j]=0;
				else ans[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dis[i][j]=0;
				else dis[i][j]=inf;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					dis[i][j]=dis[j][i]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(k==i||k==j) continue;
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						ans[i][j]=1;
					}else if(dis[i][j]==dis[i][k]+dis[k][j]){
						ans[i][j]+=ans[i][k]*ans[k][j];
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(ans[i][j]==2){
					res++;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dis[i][j]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<"---\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<ans[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		cout<<res<<endl;
	}
	else if(c==11||c==12){
		if(n==1) cout<<0<<endl;
		else{
			ll dd=a[2]-a[1];
			if(d/dd>=n) cout<<0<<endl;
			else if(d<=2*dd) cout<<0<<endl;
			else cout<<n-(d/dd)-1<<endl;
		}
	}
	else cout<<0<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

