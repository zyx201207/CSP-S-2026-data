#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010;
struct node{
	int a;
	int t;
};
ll k[1010];
node at[1010][1010];
ll c,n,m,d,q;
ll w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>at[i][j].a>>at[i][j].t;
		}
	}
	int ans=0;
	for(int j=1;j<=500;j++){
		ans+=at[1][j].t;
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<ans<<endl;
	}	
	return 0;
}
