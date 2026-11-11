#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,n,m,d,p; 
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
	}
	for(int i=1;i<=p;i++){
		cout<<abs(p+n+m+2*p-d+i*n+i*m-i*d)<<endl;
	}
	
	return 0;
}
