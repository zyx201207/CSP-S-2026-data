#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mp[505][500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			mp[i][a]=t;
		}
	}
	while(q--){
		int x,y,minx=0x3f3f3f3f,miny=0x3f3f3f3f,stai,endi;
		ll ans;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if((mp[i][x]<minx)&&(mp[i][x]!=0)){
				minx=mp[i][x];
			stai=i;}
		}
		if(mp[stai][y]!=0){
			ans=w[x]+minx+mp[stai][y]+w[y];
			cout<<ans<<'\n';
			continue;
		}else{
			for(int i=1;i<=n;i++){
			if((mp[i][y]<miny)&&(mp[i][y]!=0)){
				miny=mp[i][y];
				endi=i;}
			}
			for(int i=1;i<=m;i++){
				if(mp[stai][i]!=0&&mp[endi][i]!=0){
					ans=w[x]+minx+mp[stai][i]+mp[endi][i]+miny+w[y]; 
					cout<<ans<<'\n';
					continue;
				}
			}
		}
		
	}
	return 0;
}