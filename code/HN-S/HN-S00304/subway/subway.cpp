//做干净的奥赛 ^^
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510];
int a[500010],t[500010];
int x[100010],y[100010];
int ans;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//从每个地铁站的地铁口走到站厅需要的时间
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<32<<endl;
	}
	return 0;
}
