#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int bian,t;
	cin>>bian>>t;
	while(t--)
	{
		int n;
		long long d;
		bool c=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long cha=a[2]-a[1];
		if(2*cha>d) cout<<0<<'\n';
		else cout<<n-2*(d/cha)+1<<'\n';
	}
	return 0;
}
