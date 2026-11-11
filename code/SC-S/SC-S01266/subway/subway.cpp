#include<bits/stdc++.h>
using namespace std;
int w[500005];
vector<int> a[500005];
int c,n,m,d,q;
int main(){
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i>=n;i++){
		int t;
		cin>>t;
		while(t--){
			int ds,sj;
			cin>>ds>>sj;
			a[i].push_back(ds);
		}
	}
	while(q--){
		int qd,zd;
		cin>>qd>>zd;
		cout<<w[qd]+w[zd]<<"\n";
	}
	return 0; 
}