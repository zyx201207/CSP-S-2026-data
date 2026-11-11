#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int qwe,t; cin>>qwe>>t;
	while(t--){
		int n,k; cin>>n>>k;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++)cin>>a[i];
		int x=k/(a[1]-a[0]);
		//cout<<x<<'\n';
		if(!x) cout<<0<<'\n';
		else{
			int ans=0;
			for(int i=x;i<n;i++) ans+=((i%x)!=0?1:0)*(n-i);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
