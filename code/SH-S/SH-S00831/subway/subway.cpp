#include<bits/stdc++.h>
using namespace std;
int n,m,d,q;
int a[500],b[500][20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		for(int j=1;j<=z;j++){
			int x,y;
			cin>>x>>y;
			b[i][x]=y;
		}
	}
	while(q--){
		int x,y,cnt=0;
		cin>>x>>y;
		cnt+=a[x]+a[y];
		cnt+=b[1][y]+b[1][x]; 
		cout<<cnt;
	}
	return 0;
}
