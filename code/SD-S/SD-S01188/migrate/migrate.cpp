#include<bits/stdc++.h>
#define ll long long
#define mill 0x3f3f3f3f3f3f3f3f
using namespace std;
int c,t;
ll a[2000005];
int n;
ll l;
int fid(int x) {
	int st=x,r=n;
	ll maxx=a[x]+l;
	while(st<r) {
		int mid=(st+r+1)/2;
		if(a[mid]<=maxx) {
			st=mid;
		} else {
			r=mid-1;
		}
	}
	return st;
}
ll minn=mill,cnt=0;
void dfs(int x,int d,int stp) {
	if(x>d) {
		return ;
	}
	if(x==d) {
		if(minn>stp) {
			minn=stp;
			cnt=1;
		} else if(minn==stp) {
			cnt++;
		}
		return ;
	}
	int r=fid(x);
	for(int i=x+1; i<=r; ++i) {
		dfs(i,d,stp+1);
	}
	return ;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>l;
		for(int i=1; i<=n; ++i) {
			cin>>a[i];
		}
		int ans=0;
		for(int i=1; i<n; ++i) {
			for(int j=i+1; j<=n; ++j) {
				minn=mill;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2) {
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
