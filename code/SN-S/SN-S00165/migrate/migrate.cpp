#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
const int N=2e6+10;
int ila[N],b[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cin>>ila[1];
		bool flag=0;
		int sum=0;
		for(int i=2;i<=n;i++){
			cin>>ila[i];
			b[i-1]=ila[i]-ila[i-1];
			if(i-1>=2){
				if(b[i-1]!=b[i-2]){
					flag=1;
				}
			}
		}
		if(n==2){
			cout<<0<<'\n';
		}
		if(flag==0){
			int ans=0;
			int x=b[1];
			if(d/x<=1){
				cout<<0<<'\n';	
				continue;
			}
			int y=d/x;
			for(int i=1;i<y;i++){
				int m1=y+i;
				if(m1%2==0&&m1/2<=y) continue;
				int m2=n-m1;
				ans+=m2;
			}
			cout<<ans<<'\n';
		}
	
		
	}
	
	return 0;
}
