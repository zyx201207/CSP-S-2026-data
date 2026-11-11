#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500002]={};
vector<int> l[500002]={};	
vector<int> a[502];
vector<int> t[502];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=0;j<k;j++){
			int aa;
			cin>>aa;
			a[i].push_back(aa);
			cin>>aa;
			t[i].push_back(aa);
		}
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[1][0]*2<<'\n';
	}
	return 0;
} 
