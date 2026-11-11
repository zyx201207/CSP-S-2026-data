#include<bits/stdc++.h>

using namespace std;

#define int long long

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define endl "\n"

const int N=2e6+10;

int n,a[N],d,c,T;

void solve() {
	
	cin>>n>>d;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(d%2) {
		
		cout<<0<<endl;
		
		return ;
		
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++) {
				
		for(int j=i+3;j<=n;j++) {
			
			if((j-i+1)%2==0) {
				
				int flag=1;
						
				int t=a[i+1]-a[i];
						
				for(int x=i;x<j;x++) {
							
					if(a[x+1]-a[x]!=a[i+1]-a[i]) flag=0;
							
				}
						
				if(flag) ans++;	
				
			}
			
		}		
		
	}
	
	cout<<ans<<endl;
	
} 

signed main() {
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	IOS;
		
	cin>>c>>T;
	
	while(T--) {
	
		solve();
		
	}
	
	return 0;
	
} 
