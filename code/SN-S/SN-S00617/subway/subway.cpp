#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long ans;
long long c,n,m,d,q;
int w[N],a[600][N],t[600][N],k[N],x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				ans+=w[j]+t[j][k];
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
