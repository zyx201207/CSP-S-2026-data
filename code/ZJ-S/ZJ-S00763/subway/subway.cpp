#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int ans=0;
int w[500050],a;
int t[5010][5010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(n--){
			int k=0;
		cin>>k;
		int a;
		for(int j=1;j<=k;j++){
			cin>>a>>t[n][a];
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans+=w[x]+w[y];
		int minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			minn=min(t[i][x]+t[i][y],minn);
		}
		cout<<ans+minn<<'\n';
	}
	return 0;
}