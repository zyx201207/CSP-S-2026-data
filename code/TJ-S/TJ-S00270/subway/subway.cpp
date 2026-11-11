#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k,ans;
long long w[500005],a[505][20005],t[505][20005],x,y;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(t[1][1]==t[n][k]) {
		for(int i=1;i<=q;i++){
			ans=0;
			cin>>x>>y;
			ans=ans+w[x]+w[y];
			for(int j=x;j<y;j++){
				ans+=t[j][j+1];
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		ans+=t[x][x];
		for(int j=x;j<y;j++){
			ans+=t[j][j+1];
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
