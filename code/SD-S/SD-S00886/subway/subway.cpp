#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,M=5e5+10;
int c,n,m,d,q,w[M],x,y;
vector<int> a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	while(q--){
		cin>>x>>y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
