#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,mi,ma,b;
	cin>>c>>t;
	while(t--){
		cin>>n>>d>>mi;
		for(int i=2;i<=n;i++) cin>>ma;
		b=(ma-mi)/(n-1);
		if(d/b<2) cout<<0<<"\n";
		else cout<<max(0,n-(d/b*2-1))<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
