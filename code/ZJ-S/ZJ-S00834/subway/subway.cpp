#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int sum[N],c,n,m,d,q,w[M],a[3][M],t[3][M],k[N],vis[M],cntC[M],aC[M],x,y,ansC=1e10;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int A=1,B=1,C=1;
	if(n>2) C=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			cout<<i<<' '<<a[i][j]<<' '<<t[i][a[i][j]]<<'\n';
			vis[a[i][j]]++;
			cntC[a[i][j]]=i;
			if(a[i][j]>2) A=0;
			if(t[i][j]!=t[1][1]) B=0;
		}
	}
	if(C){
		for(int i=1;i<=m;i++){
			if(vis[i]==2){
				ansC=min(ansC,t[1][i]+t[2][i]);
				cout<<i<<' '<<t[1][i]<<' '<<t[2][i]<<'\n';
				
			}
		}
	}
	
	
	while(q--){
		cin>>x>>y;
		cout<<cntC[x]<<' '<<cntC[y]<<'\n';
		if(C){
			if(cntC[x]!=cntC[y]){
				cout<<ansC+w[x]+w[y]<<'\n';
			}
			else{
				cout<<0<<'\n';
			}
		}
		if(A||B) x++;
	}
	
	return 0;
}
