#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[505][200005],k[505],t[505][200005],x[100005],y[100005],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans+=w[x[i]];
		for(int g=1;g<=n;g++){
			for(int j=1;j<=k[i];j++){
				if(a[g][j]==x[i]) ans+=t[g][j];
				if(a[g][j]==y[i]) ans+=t[g][j];
			}
		}
		ans+=w[y[i]];
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
