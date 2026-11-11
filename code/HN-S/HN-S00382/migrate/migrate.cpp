#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int num=d/(x[2]-x[1]);
		for(int i=num+1;i<n;i++){
			if(i%num==0){
				continue;
			}
			if(i*(x[2]-x[1])/2<d){
				continue;
			}
			ans+=(n-i);
		}
		cout<<ans<<endl;
	}
}
