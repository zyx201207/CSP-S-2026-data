#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d;
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		int mid=d/(x[2]-x[1]);
		if(mid<=1) cout<<"0\n";
		else{
			ans=(n-1)*n/2;
			for(int i=1;i<=min(n,mid);i++){
				ans-=(n-i);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

