#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010];
vector<pair<int,int>> g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q; 
	for(int i=0;i<m;++i){
		cin >> w[i];
	}
	for(int i=0;i<n;++i){	
		int k;
		cin >> k;
		for(int j=0;j<k;++j){
			int l,r;
			cin >> l >> r;	
			g[l-1].push_back({i,r});
		}
	}
	if(n==2){
		vector<int> a[50010];
		for(int i=0;i<m;++i){
			for(auto j:g[i]){
				a[i].push_back(j.first);
			}
		}
		int ans=1e9;
		for(int i=0;i<m;++i){
			if(a[i].size()>1){
				ans=min(ans,g[i][0].second+g[i][1].second);
			}
		}
		for(int f=0;f<q;++f){
			int l=0,r=0;
			cin >> l >> r;
			if(a[l-1].size()==1&&a[r-1].size()==1&&a[l-1][0]!=a[r-1][0])cout << ans+w[l-1]+w[r-1]+g[l-1][0].second+g[r-1][0].second << endl;
			else cout << w[l-1]+w[r-1]+g[l-1][0].second+g[r-1][0].second << endl;
		}
	}
	if(n==1){
		for(int f=0;f<q;++f){
			int l=0,r=0;
			cin >> l >> r;
			cout << w[l-1]+w[r-1]+g[l-1][0].second+g[r-1][0].second << endl;
		}
	}
	return 0; 
}