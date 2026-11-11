#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)  cin>>a[i];
		int m=a[2]-a[1],k=d/m;
		if(k<=1||n-2*k+1<=0)  cout<<0<<'\n';
		else  cout<<n-2*k+1<<'\n';
	}
	return 0;
}
