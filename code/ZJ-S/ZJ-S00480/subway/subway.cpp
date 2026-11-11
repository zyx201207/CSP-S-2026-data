#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,n,m,d,q,mt[500010];
short nti[500010];
long long jl[510][510];
pair<int,int> nt[500010][22];
signed main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>mt[i];
	}
	for(int i=1; i<=n; i++) {
		int ki;
		cin>>ki;
		for(int j=1; j<=ki; j++) {
			int a,t;
			cin>>a>>t;
			nt[a][++nti[a]].first=i,nt[a][nti[a]].second=t;
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			if(i==j)jl[i][j]=0;
			else jl[i][j]=1e18;
		}
		
		
	for(int i=1; i<=m; i++) {
		for(int j=1; j<nti[i]; j++) {
			int noe=nt[i][j].first,now=nt[i][j].second;
			for(int h=j+1; h<=nti[i]; h++) {
				int ne=nt[i][h].first,nw=nt[i][h].second;
				jl[noe][ne]=min(jl[noe][ne],(long long)now+nw);
				jl[ne][noe]=min(jl[ne][noe],(long long)now+nw);
			}
		}
	}
	for(int h=1; h<=n; h++) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				jl[j][i]=jl[i][j]=min(jl[i][j],jl[i][h]+jl[j][h]);
			}
		}
	}
	while(q--) {
		int xi,yi;
		cin>>xi>>yi;
		long long ans=1e18;
		for(int i=1; i<=nti[xi]; i++) {
			for(int j=1; j<=nti[yi]; j++) {
				int fi1=nt[xi][i].first,si1=nt[xi][i].second;
				int fi2=nt[yi][j].first,si2=nt[yi][j].second;
				ans=min(ans,jl[fi1][fi2]+si1+si2);
			}
		}
		cout<<ans+mt[xi]+mt[yi]<<'\n';
	}

	return 0;
}

