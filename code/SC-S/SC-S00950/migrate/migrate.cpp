#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
using LL=long long;
LL a[N];
LL k,di,d,cnt;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		LL ans=0;
		LL n;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		LL gc=a[2]-a[1];
		if(d<gc*2)cout<<0<<endl;
		else
		{
			LL s=d/gc*2-1;
			cout<<n-s<<endl;
		}
	}
	return 0;
}