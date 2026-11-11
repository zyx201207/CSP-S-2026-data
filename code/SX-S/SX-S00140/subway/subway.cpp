#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[1010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;cin>>a>>b;
		}
	}
	int a,b;
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		cout<<w[a]+w[b]<<endl;
	}
	return 0;
}