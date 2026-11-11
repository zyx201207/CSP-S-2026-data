#include<bits/stdc++.h> 
using namespace std;
int n;
long long int m,a[500005],d[500005],s=1,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000)
	{
		int m1;
		m1=m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			d[i]=a[i]-a[i-1];
		}
		for(int i=n;i>=2;i--)
		{
			int j=i-1;
			s=1;
			m=m1;
			while(j>0)
			{
				int r=0;
				for(int q=j+1;q<=i;q++)
				{
					r+=d[q];
				}
				m-=r;
				if(m<0) break ;
				j--;
				s++;
			}
			ans=max(ans,s);
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			d[i]=a[i]-a[i-1];
		}
		int q;
		q=m/d[1];
		for(int i=1;i<=n;i++)
		{
			if(q-i*d[1]<0) break;
			q=q-i*d[1];
			s++;
		}
		cout<<s;
	}
	return 0;
}
