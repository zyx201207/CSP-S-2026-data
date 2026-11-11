#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,t,g[2000006],r[2000006],l[2000006];
ll d,x[2000006];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			r[i]=upper_bound
			(x+i+1,x+n+1,x[i]+d)-x-1;
			l[i]=lower_bound
			(x+1,x+i+1,x[i]-d)-x;
			g[i]=r[i]-l[i];
		}
		for(int i=1;i<n;i++)
			if(g[i]==g[i+1]&&g[i]!=g[i+2]&&
			   g[i]!=g[i-1])ans++; 
		for(int i=2;i<n;i++)
			if(g[i-1]==g[i+1]&&
			   g[i-1]+1==g[i])ans+=2; 
		cout<<ans<<"\n";
	}
	return 0;
}

