#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+10;
ll t,n,d,ans;
ll a[N],cnt[N][N];
vector<int>ve[N];
ll dfs(ll x,ll y,ll z) {
	for(ll i=0;i<ve[x].size();i++) {
		if(cnt[x][ve[x][i]]>cnt[y][x]+a[ve[x][i]]-a[x]) {
			cnt[x][ve[x][i]]=cnt[y][x]+1;
			ans=z;
		}
		else if(cnt[x][ve[x][i]]==cnt[y][x]+a[ve[x][i]]-a[x]) {
			ans++;
			
		}
		dfs(ve[x][i],0,0);
	}
	
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>d;
		memset(cnt,0x3f,sizeof cnt);
		memset(ve,0,sizeof ve);
		ans=0;
		
		for(int i=1;i<=n;i++) {
			cin>>a[N];
		}
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++) {
				ve[a[i]].push_back(a[j]);
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
