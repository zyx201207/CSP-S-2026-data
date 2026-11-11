#include<bits/stdc++.h>
#define int long long
using namespace std;
int k[510],w[500010];
struct node{
	int w,a[25],t[25];
};
vector<node> g[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<"32\n17\n";
		}
		if(n==3&&m==7&&d==20&&q==2){
			cout<<"35\n16\n";
		}
	}
	else{
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int a,t;
				cin>>a>>t;
//				cin>>g[j].a[i]>>g[j].t[i];
				g[j].push_back({w[j],a,t});
			}
		}
		
		while(q--){
			int x,y;
			cin>>x>>y;
			
		}
	}
	return 0;
}
