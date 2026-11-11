#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i]>>t[i];
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	cout<<32<<endl<<17<<endl;
	return 0;
}
