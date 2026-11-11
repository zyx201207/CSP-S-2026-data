#include<iostream>
#include<algorithm>
using namespace std;
int g[10005][10005];
int w[10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,b,q;
	cin>>c>>n>>m>>b>>q;
	int s=0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>g[i][n];
	}	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y];
	}
	return 0; 
} 
