#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000006;
int c,t,n,d,x[N],cnt,minway;
void dfs(int u,int meet,int goal) {
//	cout<<u<<" "<<meet<<" "<<goal<<endl;
	if(minway<meet)return;
	if(u==goal) {
		if(minway==meet)cnt++;
		else minway=meet,cnt=1;
		return;
	}
	for(int i=u+1; i<=goal; i++)
		if(x[i]-x[u]<=d)
			dfs(i,meet+1,goal);
}
bool p(int x,int y) {
	cnt=0;
	minway=0x3f3f3f3f;
	dfs(x,1,y);
	return cnt==2;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		int ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>x[i];
		for(int i=1; i<n; i++)
			for(int j=i+1; j<=n; j++)
				if(p(i,j))ans++;
		cout<<ans<<endl;
	}
}
