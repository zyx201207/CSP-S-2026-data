#include<bits/stdc++.h>
using namespace std;
long long w[1005],a[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,q,d,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[i][j];
	}
	long long ans=0;
	for(int i=1;i<=q;i++){
		int s,f;
		cin>>s>>f;
		ans+=w[s]+w[f];
		if(n==1)
			cout<<ans;
	}
}
