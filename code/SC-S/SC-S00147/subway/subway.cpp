#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,summ,sum[100005],x[100005],y[100005],w[500005],k[505],a[505][50005],t[505][5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		summ+=w[x[i]]+w[y[i]];
		for(int j=x[i];j<y[i];j++){
			for(int p=j;p<=y[i];p++){
				summ+=t[j][p]; 
			}
		}
		cout<<summ<<'\n';
	}
	return 0;
}