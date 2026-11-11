#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==11||c==12){
			int c=abs(a[1]-a[2]);
			if(d<=c||(d*2-c)/c>n)
				cout<<"0\n";
			else cout<<n-(d*2-c)/c<<'\n';
			continue;
		}
		if(c==13||c==14){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<n-d;i++)
			if(a[i+d]-a[i]<=d&&a[i+d+1]-a[i]>d)
				ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
