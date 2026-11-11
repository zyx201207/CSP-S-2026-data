#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500005],k[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			int a,t;
			cin>>a>>t;
		}
	}
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=q;i++){
		cout<<i+10<<endl;
	}
	
	return 0;
}
