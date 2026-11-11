#include<bits/stdc++.h>
using namespace std;

long long n,m,l,tmp,len,ans=1;
long long a[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		len=1;
		tmp=0;
		l=i;
		while(tmp<=m)
		{
			int il=0;
			if(l>=2)
			{
				l=l-1;
				il++;
			}
			if(!il)
			{
				len++;
				break;
			}
			else
			{
				tmp+=a[i]-a[l];
				len++;
			}
		}
		ans=max(len-1,ans);
	}
	cout<<ans;
	return 0;
}
