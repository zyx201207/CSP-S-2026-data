#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,i,r[9999][9999],j,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<ll>a(m+1);
	for(i=1;i<=m;i++)cin>>a[i];
	for(i=0;i<9999;i++)for(j=0;j<9999;j++)r[i][j]=2e18;
	for(i=0;i<9999;i++)r[i][i]=0;
	while(n--){
		cin>>k;vector<pair<ll,ll>>o(k);
		for(auto&u:o)cin>>u.first>>u.second;
		for(i=0;i<k;i++)
			for(j=i+1;j<k;j++)r[o[i].first][o[j].first]=r[o[j].first][o[i].first]=min(r[o[j].first][o[i].first],o[i].second+o[j].second);
	}
	for(i=1;i<=m;i++)for(j=i+1;j<=m;j++)for(k=1;k<=m;k++)r[i][j]=r[j][i]=min(r[i][j],r[i][k]+r[k][j]);
	while(q--)cin>>i>>j,cout<<a[i]+a[j]+r[i][j];
	return 0;
}
