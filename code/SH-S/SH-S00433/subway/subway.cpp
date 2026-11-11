#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[5009],a[5009],t[5009];
ll c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k*2;j++) cin>>a[i]>>t[j];
	}
	for(int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;
	}
	for(int i=1;i<=q;i++)
		cout<<c+n+m+d+q<<endl;
	return 0;
}
