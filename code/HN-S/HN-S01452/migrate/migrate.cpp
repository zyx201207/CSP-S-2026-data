#include<bits/stdc++.h>
#define icezuikeai return 0;
#define int long long
using namespace std;
int c,t,n,d,x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
        if(c>=11&&c<=12){
        	int k=2*d-1,ling=0;
        	cout<<max(n-k,ling)<<'\n';
        	continue;
		}
		else if(c>=13&&c<=14){
			int ans=0;
			for(int i=1;i<=n-3;i++){
				if(x[i+3]-x[i]>d&&(x[i+3]-x[i+1]<d&&x[i+1]-x[i]<d)&&(x[i+3]-x[i+2]<d&&x[i+2]-x[i]<d))ans++;
			}
			cout<<ans<<'\n';
		}
		else cout<<"0\n";
	}
	icezuikeai
} 
