#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],x,l,r;
vector<int>e[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x;
			e[i].push_back(x);
		}
	}
	while(q--){
		cin>>l>>r;
		cout<<(l+r)*8<<"\n";
	}
	return 0;
}
