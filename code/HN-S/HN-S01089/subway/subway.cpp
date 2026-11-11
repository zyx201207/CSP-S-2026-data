#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=n;i++)cin>>w[i];
	while(n--){
		int k;
		cin>>k;
		int a[k+1];
		for(int i=1;i<=k;i++)cin>>a[i];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}

