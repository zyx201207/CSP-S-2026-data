#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[2*N],c,tt,n,d,s[10*N],ans;
int main()
{
	freopen("migrate.in","r",stdin);//记得改txt为in 
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>tt;
	while(tt--)
	{
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		ans=0;
		cin>>n>>d;
		for(int i = 1;i <= n;++i)
		{
			cin>>a[i];
		}
		for(int i = 1;i <= n;++i)
		{
			if(a[i]+d>a[n])
			{
				break;
			}
			int kkk=a[i]-a[1];
			for(int j = 0;j < d;++j)
			{
				s[kkk+j]++;
			}
		}
		for(int i = 1; i <= 1e7+20;++i)
		{
			if(s[i]==2)
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 