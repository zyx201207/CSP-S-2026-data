#include<bits/stdc++.h>
using namespace std;
#define ll long long
short c;
ll t,x[2000001];
short check(ll st,ll d)
{
	for(int i=st+1;i<=st+3;i++)
		if(x[i]-x[i-1]>d)return -1;
	return bool(x[st+3]-x[st]>d&&x[st+2]-x[st]<=d);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(x,0,sizeof(x));
		long long ans=0,n,d;
		cin>>n>>d;
		for(ll i=0;i<n;i++)
			cin>>x[i];
		for(ll u=0;u<n-3;u++)
		{
			for(ll v=u+3;v<n;v++)
			{
				long long num=0;
				bool b=1;
				for(ll st=u;st+3<=v;st++){
					if(check(st,d)==-1)b=0;
					else num+=check(st,d);
				}
				if(num==1&&b)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
