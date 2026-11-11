#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	
	cin>>c>>n>>m>>d>>q;
	int w[10000];//时间 
	for(int i=1;i<=d;i++){
		cin>>w[i];
	}
	int t[10000];//时间1 
	int k[10000];//线路个数 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>t[i];
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x]+t[y]<<endl;
	}
return 0;	
}
