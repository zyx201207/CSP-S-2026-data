#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100001],k[100001],a[10001][10001],t[10001][10001],x[10001],y[10001],ans;
vector <int> g[10001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j][i]>>t[j][i];
			g[i].push_back(a[j][i]);
		}
	} 
	while(q--){
		cin>>x[q]>>y[q];
		ans+=w[x[q]]+w[y[q]];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=i;j++){	
				if(abs(j-i)>1 or j>=y[q]) continue;
				else {
					ans+=t[j][i];
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}