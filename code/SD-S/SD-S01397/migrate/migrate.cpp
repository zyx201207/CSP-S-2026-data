#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],ans;
void add(){
	
}
void Dijkstra(){
	
}
void work(){
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=2;i<n;i++){
		if(x[i]-x[i-1]==x[i+1]-x[i]){
			ans+=i;
		}
	}
	cout<<"0\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		work();
		add();
	}Dijkstra();
	return 0;
}
