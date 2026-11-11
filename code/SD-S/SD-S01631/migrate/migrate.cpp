#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ans,bo,minn,vis[2000005];
void dfs(long long x,long long z,long long c) {
	if(c>vis[x]) return;
	vis[x]=c;
	if(x==z) {
		if(minn==c) bo++;
		if(minn>c) {
			minn=c;
			bo=1;
		}
		return;
	}
	long long now=x+1;
	for(; now<=z; now++) {
		if(a[now]-a[x]>d) {
			now--;
			break;
		}
	}
	for(long long i=now; i>=x+1; i--) {
		dfs(i,z,c+1);
	}
	return;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(long long i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(long long len=4; len<=n; len++) {
			for(long long l=1; l<=n; l++) {
				long long r=l+len-1;
				if(r>n) continue;
				minn=1e9;
				bo=0;
				for(int i=l; i<=r; i++) {
					vis[i]=1e18;
				}
				dfs(l,r,0);
				ans+=(bo==2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//DP?(me dfs)
