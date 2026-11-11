#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,d,x[2000010],a[310][310],dis[310][310];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		sort(x+1,x+n+1);
		int dd=x[2]-x[1];
		bool f=true;
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=dd){
				f=false;
				break;
			}
		}
		if(f){
			if(dd>=d){
				cout<<0<<endl;
				continue;
			}
			int r=d/dd;
			if(r==1||r>=3){
				cout<<0<<endl;
				continue;
			}
			cout<<max(n-3,0ll)<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
