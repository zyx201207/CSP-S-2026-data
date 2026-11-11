#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,a,t,x,y;
long long w[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<2*w[x]+3*w[y]<<endl;
	}
	return 0;
}
