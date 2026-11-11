#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define il inline

const int N=2e6+5,mod=1e9+7,INF=(1LL<<60);

int c,t,l,minn=1e9,ans;
int n,d,x[N];
void dfs(int y,int z,int sum){
	if(sum>minn) return;
	if(y==z){
		if(minn==sum) l++;
		else if(minn>sum) minn=sum,l=1;
		return;
	}
	int i;
	for(i=y+1;i<=z;i++){
		if(x[i]-x[y]>d) break;
	//	dfs(i,z,sum+1);
	}
	for(int j=i-1;j>=y+1;j--) dfs(j,z,sum+1);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		l=0;minn=1e9;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=5000){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					l=0;minn=n+1;
					dfs(i,j,0);
					if(l==2) ans++;
				}
			}
			cout<<ans<<'\n';
			ans=0;
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}

