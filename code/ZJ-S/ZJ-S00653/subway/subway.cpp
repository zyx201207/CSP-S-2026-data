#include<bits/stdc++.h>
using namespace std;
int w[500010],a[500010],t[500010];
vector<pair<int,int> > mp[500010];
int main(){
	freopen("subway1.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cin>>a[1]>>t[1];
		for(int i=2;i<=k;i++){
			cin>>a[i]>>t[i];
			mp[a[i]].push_back({(t[i]+t[i-1]),a[i-1]});
			mp[a[i-1]].push_back({(t[i]+t[i-1]),a[i]});
		}
	}
	while(p--){
		int l,r;
		cin>>l>>r;
		int ret=w[l]+w[r];
		cout<<ret+mp[l].first+mp[r].first<<endl;
	}                                
	return 0;
}