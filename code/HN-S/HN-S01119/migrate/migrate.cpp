#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[10];
long long z;
long long minn;
void dfs(int x,int y,int now,int sum,int d) {
	if(now==y) {
		if(sum==minn) {
			z++;
		} else if(sum<minn) {
			z=1;
			minn=sum;
		}
		return;
	}
	int j=now+1;
	while(j<y&&(a[j]-a[now])<=d) {
		dfs(x,y,j,sum+1,d);
		j++;
	}
}
void solve() {
	int n;
	long long d;
	int ans=0;
	cin>>n>>d;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			z=0;
			minn=LONG_LONG_MAX;
			dfs(i,j,i,0,d);
			if(z==2) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		solve();
	}
	return 0;
}

