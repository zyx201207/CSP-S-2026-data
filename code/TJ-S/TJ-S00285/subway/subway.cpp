#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[2010][510];
vector<int> p[510];
vector<int> cl[2010];
int c,n,m,d,q;
int l,r;
int minn=LLONG_MAX;
int w[500010];
int fg[2010][510];
void dfs(int ol,int sum){
	if (ol==r){
		minn=min(minn,sum+w[r]);
		return;
	}
	if (sum>minn){
		return;
	}
	for (auto it:cl[ol]){
		fg[ol][it]=1;
		for (auto ip:p[it]){
			if (ip==ol){
				continue;
			} 
			if (fg[ip][it]==0){
				fg[ip][it]=1;
				dfs(ip,sum+f[ol][it]+f[ip][it]);
				fg[ip][it]=0;
			}
		}
		fg[ol][it]=0;
	}
}
int mn=LLONG_MAX;
int lzy[500010][2];
int qs=0;
int ans,ml=LLONG_MAX;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	if (c==20 || c==21){
		for (int i=1;i<=n;i++){
			int k;
			cin >> k;
			for (int j=1;j<=k;j++){
				int a,t;
				cin >> a >> t;
				lzy[a][i]=t;
			}
		}
		for (int i=1;i<=m;i++){
			if (lzy[i][1]!=0 && lzy[i][2]!=0){
				if (lzy[i][1]+lzy[i][2]<mn){
					mn=lzy[i][1]+lzy[i][2];
				}
			}
		}
		ml=LLONG_MAX;
		while (q--){
			cin >> l >> r;
			ans=LLONG_MAX;
			if (lzy[l][1]!=0 && lzy[r][1]!=0){
				ans=min(ans,w[l]+lzy[l][1]+lzy[r][1]+w[r]);
			}
			if (lzy[l][2]!=0 && lzy[r][2]!=0){
				ans=min(ans,w[l]+lzy[l][2]+lzy[r][2]+w[r]);
			}
			if (ans<ml){
				cout << ans << '\n';
			}
			else{
				if (lzy[l][1]!=0 && lzy[r][2]!=0){
					cout << w[l]+lzy[l][1]+mn+lzy[r][2]+w[r] << '\n';
				}
				else if (lzy[l][2]!=0 && lzy[r][1]!=0){
					cout << w[l]+lzy[l][2]+mn+lzy[r][1]+w[r] << '\n';
				}
			}
		}
	}
	else{
		for (int i=1;i<=n;i++){
			int k;
			cin >> k;
			for (int j=1;j<=k;j++){
				int a,t;
				cin >> a >> t;
				f[a][i]=t;
				cl[a].push_back(i);
				p[i].push_back(a);
			}
		}
		while (q--){
			cin >> l >> r;
			minn=LLONG_MAX;
			memset(fg,0,sizeof(fg));
			dfs(l,w[l]);
			cout << minn << '\n';
		}
	}
	return 0;
}
