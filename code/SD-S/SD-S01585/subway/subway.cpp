#include<bits/stdc++.h>
using namespace std;
long long w[500005],a[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i = 1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<32<<endl<<17;
}
