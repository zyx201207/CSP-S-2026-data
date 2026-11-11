#include<bits/stdc++.h>
using namespace std;
int c,T,n,d;
long long a[2000010],dc,x;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		dc=a[2]-a[1];
		x=d/dc;
		if(n-x-2>=0) cout<<n-x-1<<endl;
		 else cout<<0<<endl;
	}
	return 0;
}
