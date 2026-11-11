#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
vector<int> G[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a[50],t[50];
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
		for(int i=1;i<k;i++){
			G[a[i]].push_back(a[i+1]);
			G[a[i+1]].push_back(a[i]);
		}
			
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<(w[x]+w[y])*2;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}