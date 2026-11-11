//汤佳忆 西安辅轮中学 SN-S00432 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int c,t; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=3;i<=d+1;++i){
			ans+=n-i;
		}
		cout<<ans;
	}
	
	
	return 0;
}
