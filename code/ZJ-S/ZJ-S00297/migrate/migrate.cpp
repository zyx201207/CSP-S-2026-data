#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=5000+5;
int n,d,x[Maxn];
int E[Maxn][Maxn],Min_Dis,Cnt;
int Answer;
inline void DFS1(int u,int v) {
	if(u==v)
		return;
	for(register int i=u+1; i<=v; ++i) {
		if(x[i]-x[u]>d)
			break;
		E[u][i]=1;
		DFS1(i,v);
	}
}
inline void DFS2(int u,int v,int dis) {
	if(u==v) {
		Min_Dis=min(Min_Dis,dis);
		return;
	}
	for(register int i=u+1; i<=n; ++i)
		if(E[u][i])
			DFS2(i,v,dis+1);
}
inline void DFS3(int u,int v,int dis,int sp) {
	if(u==v&&sp==dis) {
		++Cnt;
		return;
	}
	for(register int i=u+1; i<=n; ++i)
		if(E[u][i])
			DFS3(i,v,dis+1,sp);
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	int tmp;
	while(t--) {
		for(register int i=1; i<=n; ++i)
			for(register int j=0; j<=n; ++j)
				E[i][j]=0;
		Answer=0;
		cin>>n>>d;
		for(register int i=1; i<=n; ++i)
			cin>>x[i];
		DFS1(1,n);
//		for(register int i=1; i<=n; ++i) {
//			for(register int j=1; j<=n; ++j)
//				cout<<E[i][j]<<" ";
//			cout<<endl;
//		}
		for(register int i=1; i<=n; ++i)
			for(register int j=i+1; j<=n; ++j) {
				Min_Dis=1e18;
				DFS2(i,j,0);
//				cout<<i<<" "<<j<<" "<<Min_Dis<<endl;
				if(Min_Dis!=1e18) {
					Cnt=0;
					DFS3(i,j,0,Min_Dis);
					if(Cnt==2)
						++Answer;
				}
			}
		cout<<Answer<<endl;
	}
//	cout<<"-_-"<<endl;
	return 0;
}