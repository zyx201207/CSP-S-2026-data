#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,kt[503];
vector<int,pair<int,int> > t[503],mp[503];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>kt[i];
	for(int i=1;i<=n;i++){
		int k,aa[303],cnt=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int z,zz;
			cin>>z>>zz;
			a[++cnt]=z;
			t[z].push_back(make_pair(i,zz));
			for(int i=1;i<=cnt;i++){
				mp[a[i]].push_back(z);
				mp[z].push_back(a[i]);
			}
		}
	}
	return 0;
}