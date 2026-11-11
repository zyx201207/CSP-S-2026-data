//马知遥 西安交通大学附属中学 SN-S00380  
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,m;
	cin>>c>>t;
	while(t--){
		int d;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		d=a[2]-a[1];
		int w=m/d;
		int ans=0;
		for(int i=2;i<=n;i++){
			if((n%2!=1 || i!=n) && i-((i-1)/w)*w+1==2){
				ans+=(n-i);
//				cout<<"now:"<<i<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}
