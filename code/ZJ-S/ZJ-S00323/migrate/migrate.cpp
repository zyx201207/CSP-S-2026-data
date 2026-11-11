#include<iostream>
#define int long long
using namespace std;
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d,x,y,a;
		cin>>n>>d>>x>>y;
		for(int i=3;i<=n;i++)cin>>a;
		int del=y-x;
		if(d<=del)cout<<0<<'\n';
		else cout<<max(n-((d/del-1)*2+2)+1,0LL)<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
}