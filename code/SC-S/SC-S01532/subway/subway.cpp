#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],x[100005],y[100005],jiao[100005];
struct xmj{
	int a;int t;
}ws[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>ws[j].a>>ws[j].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int ans=w[x[i]]+w[y[i]];
		cout<<ans;
	}
	return 0;
}