#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t[5005][5005],w[5005],k[5005],a[5005][5005],c,d,q;
vector<int>v[5005],vv[5005];
map<int,bool>mapp,mmm;
int dfs(int l,int r,int jj) {
	int ans=INT_MAX;
	if(mapp[l]){
		return -1;
	}
	mapp[l]=1;
	for(int i=0; i<v[l].size(); i++) {
		for(int j=0; j<vv[v[l][i]].size(); j++) {
			if(vv[v[l][i]][j]!=l) {
				if(vv[v[l][i]][j]==r) {
					return jj+1;
				} else {int kkk=dfs(vv[v[l][i]][j],r,jj+t[i][j]);
					if(kkk!=-1) 
						ans=min(ans,kkk);
				}
			}
		}
	}
	if(ans==INT_MAX){
		return -1;
	}
	return ans;
}

signed  main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[j][i]>>t[j][i];
			v[a[j][i]].push_back(i);
			vv[i].push_back(a[j][i]);
		}
	}
	while(q--) {
		int l,r;
		cin>>l>>r;
		cout<<dfs(l,r,0)+w[l]+w[r]<<endl;
		mapp=mmm;
	}
}

