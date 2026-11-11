#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[500005],a[505][500005],t[505][500005];
ll ans=0;
int c,n,m,d,q;
void solve(){
	int x,y;
	cin>>x>>y;
	ans=ans+w[x]+w[y];
	if(c>=7&&c<=11){
		for(int i=x;i<=y-1;i++)ans+=t[i][i+1];
		cout<<ans;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--)solve();
	return 0;
}

