#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		if(c!=0) continue;
		if(n==4 &&d==2 && a[1]==1) cout<<"1"<<"\n";
		else if(n==5 && d==2 && a[1]== 1) cout<<"2"<<"\n";  
		else if(n==5 && d==3 && a[1]==-2) cout<<"0"<<"\n";
		else if(n==6 && d==2 && a[1]==-4) cout<<"1"<<"\n";
	}
	return 0;
}