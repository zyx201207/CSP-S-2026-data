#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,p,x,y;
vector<long long>w,k,a[510],t[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>p;
		w.push_back(p);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>p;
			a[i].push_back(p);
			cin>>p;
			t[i].push_back(p);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}

