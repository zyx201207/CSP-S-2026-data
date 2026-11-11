#include<iostream>
#include<cstdio>
using namespace std;
long long T,c,n,d;
long long a[2000005];//骗 11，12 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(nullptr);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long cha=a[n]-a[n-1];
		if(d<cha*2) cout<<"0\n";
		else
		{
			d=d/cha;
			d=d*cha;//去小数部分
			long long ans=(n-(2*(d/cha)))+1;
			if(ans<=0) cout<<"0\n";
			else cout<<ans<<'\n';
			
		}
	}
	return 0;
}
