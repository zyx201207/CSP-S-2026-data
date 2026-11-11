#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],ans[2000005],ansx[2000005],flag,cnt;
void fs(int step,int l)
{
	if(ans[step]>l)
	{
		ans[step]=l;
		ansx[step]=1;
	}
	else if(ans[step]==l)
	{
		ansx[step]++;
	}
	if(step>n+2)
	{
		return ;
	}
	for(int i=1;i<=d;i++)
	{
		fs(step+i,l+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(x,0,sizeof(x));
		memset(ans,0x3f,sizeof(ans));
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		fs(1,1);
		for(int i=1;i<=n;i++)
		{
			if(ansx[i]==2)
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
