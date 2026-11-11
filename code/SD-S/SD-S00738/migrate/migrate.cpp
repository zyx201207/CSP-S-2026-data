#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000010],ans,num;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=num=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d<2*(a[2]-a[1])){
			cout<<0<<"\n";
			continue;
		}
		num=d/(a[2]-a[1]);
		num=2*num;
		ans=n-num+1;
		cout<<max(ans,(long long)0)<<"\n";
	}
	return 0;
}
