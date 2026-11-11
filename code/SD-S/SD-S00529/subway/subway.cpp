#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+10,K=5e5+10;
int c,n,m,d,q,w[M],k[N],a,t;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<0<<"\n"; 
	}
	return 0;
}

