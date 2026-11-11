#include<bits/stdc++.h>
#include<ctime>
using namespace std;

const int N=5e5+9;
int c,n,m,d,q,k;
int a[N];
int t[1004][1004];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=2*k;j++)cin>>t[i][j];
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<a[x]+a[y]+t[x][y]+t[x][x]+t[y][y]<<endl;
	}
	
} 
