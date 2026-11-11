#include<iostream>
#include<cstring>
using namespace std;
int c,n,m,d,q;
int a[505][505];
int k[505];
void dfs(int x,int tim){
	for(int i=1;i<=n*m;i++){
		if(a[i][i]){
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i][2*m+i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x>>a[(i+2)*m][x];
			a[x][(i+2)*m]=a[(i+2)*m][x];
			a[x][(i+2)*m]=a[(i+2)*m][x]=0;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dfs(x,0);
		cout<<"²»»á"; 
	}
}
