#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;
int c,t,n,d;
int x[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=d;i++){
			if(x[i]+d+1<=n) ans++;
		} 
		cout<<ans<<'\n';
	}
	return 0;
} 

	
