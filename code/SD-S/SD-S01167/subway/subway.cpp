#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,i,j,ans;
vector<long long> w;
vector<vector<long long> > a;
vector<vector<long long> > t;
vector<long long> x;
vector<long long> y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		int k; cin>>k;
		for(long long j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	for(long long i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(long long i=1;i<=q;i++){
		ans=0;
		for(int j=x[i];j<=y[i];j++){
			ans+=w[i]+t[i][j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
