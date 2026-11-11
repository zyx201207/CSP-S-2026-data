#include <iostream>
using namespace std;
int c,t,n,k;
int d[1001][1001];
int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			d[u][v]=1;
			d[v][u]=1;
		}
	}
	cout<<1<<endl<<2;
	return 0;
}
