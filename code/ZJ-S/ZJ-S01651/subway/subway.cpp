#include<bits/stdc++.h>
using namespace std;
long long a[501][501];
vector<int>vc[500001],val[500001];
long long w[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway7.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			vc[x].push_back(i),val[x].push_back(y);
		}
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
		a[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<vc[i].size();j++){
			for(int k=0;k<vc[i].size();k++)
				a[vc[i][j]][vc[i][k]]=min(a[vc[i][j]][vc[i][k]],(long long)val[i][j]+val[i][k]);
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][l]+a[l][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<vc[x].size();i++){
			for(int j=0;j<vc[y].size();j++)
				ans=min(ans,w[x]+w[y]+val[x][i]+val[y][j]+a[vc[x][i]][vc[y][j]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}