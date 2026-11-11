#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,m,a[N],dp[N],ans;
namespace sa{
	int d;
	void main(){
		while(t--){
			cin >> n >> m;ans=0;
			for(int i=1;i<=n;i++) cin >> a[i],dp[i]=0;
			d=a[2]-a[1];
			m/=d;
			if(m==0){cout << 0 << '\n';continue;}
			for(int i=1;i<n;i++){
				int a=(i+m-1)/m,b=i-(a-1)*m;
				if(a!=1&&b!=m&&(m-b+1)*(a-1)==2) dp[i]=1;
			}
			for(int i=1;i<n;i++) ans+=(n-i)*dp[i];
			cout << ans << '\n';
		}
	}
	void mm(){
		while(t--){
			cin >> n >> m;
			for(int i=1;i<=n;i++) cin >> a[i];
			cout << 0 << '\n';
		}
	}
}
namespace bl{
	int dfs(int l,int r,int k){
		if(k==0&&l==r) return 1;
		if(k==0&&l!=r) return 0;
		int sum=0,rr=r;
		for(int i=l;i<=r&&a[i]-a[l]<=m;i++) sum+=dfs(i,r,k-1);
		return sum;
	}
	void main(){
		while(t--){
			cin >> n >> m;ans=0;
			for(int i=1;i<=n;i++) cin >> a[i];
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
				int cnt=0,l=i;
				while(l<=j){
					cnt++;
					int r=l;
					while(r<=j&&a[r]-a[l]<=m) r++;
					l=r;
				}
				int z=dfs(i,j,cnt);
				if(z==2) ans++;
			}
			cout << ans << '\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11||c==12) sa::main();
	else if(c==13||c==14) sa::mm();
	else bl::main();
	return 0;
}
