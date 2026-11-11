#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int c,n,m,d,q,x,y;
long long a[N][N],t[N][N],cnt[N][N],w[N],s;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
		cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		s=k;
		for(int j=1; j<=k; j++) {
			cin>>a[i][k]>>t[i][k];
		}
		cnt[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
	}
	if(s==2) {
		while(q--) {
			cin>>x>>y;
			int ans=w[x]+w[y];
			for(int i=1; i<=n; i++){
				if(a[i][1]+a[i][2]==x+y)
					cout<<ans+cnt[a[i][1]][a[i][2]]<<endl;
				else {
					for(int j=1; j<=2; j++) 
						ans+=t[i][j];
					cout<<ans<<endl;
				}
			}
		}
	}
	else{
		while(q--) {
			cin>>x>>y;
			int ans=w[x]+w[y];
			int maxn=max(x,y),minn=min(x,y);
			ans=ans+(maxn-minn)*t[x][1];
			cout<<ans<<endl;
		}
	}
}
