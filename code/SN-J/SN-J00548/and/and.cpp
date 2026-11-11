#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define vi void
using namespace std;

const int N=2e5+5;

int n,m,mx=-1,sn=INT_MAX,ans=-1;
int a[N],dp[N];
//bool ch[N];

vi dfs(int x,int cnt,int num) {
	if(cnt==m) {
		ans=max(ans,num);
//		cout<<x<<' '<<cnt<<' '<<num<<' '<<ans<<'\n';
		return;
	}
	if(n-x+1<m-cnt) {
//		cout<<x<<' '<<cnt<<' '<<n-x+1<<' '<<m-cnt<<"!\n";
		return;
	}
	if(x==n+1) {
		return;
	}
	dfs(x+1,cnt+1,num&a[x]);
	dfs(x+1,cnt,num);
}


int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
		sn&=a[i];
	}
	if(m==1) cout<<mx;
	else if(m==n) cout<<sn;
	else {
		dfs(1,0,INT_MAX);
		cout<<ans;
	}
	return 0;
}
