#include<bits/stdc++.h>

using namespace std;

long long c,n,m,d,q,w[200005],a[1005][1005],maxx;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		for(int j=1;j<=x;j++){
			long long y,z;
			cin>>y>>z;
			a[i][y]=z;
		}
	}
	for(int i=1;i<=q;i++){
		int f,t;
		cin>>f>>t;
		maxx=1e9;
		for(int j=1;j<=n;j++){
			maxx=min(maxx,a[j][f]+a[j][t]);
		}
		if(maxx>100){
			maxx-=1e9;
		}
		cout<<maxx+w[f]+w[t]<<endl;
	}
	return 0;
}	
