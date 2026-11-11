#include<bits/stdc++.h>
using namespace std;
int n,m[200005],c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char cc;
		cin>>m[i]>>cc;
		c[i]=cc;
	}
	int i=1,j=n;
	long long ans=0;
	while(i!=j)
	{
		if(m[i]>m[j])
		{
			if(c[i]==c[j])
			{
				m[i]-=m[j];
				j--;
			}
			else
			{
				ans+=m[j];
				m[i]-=m[j];
				j--;
			}
		}
		else
		{
			if(c[i]==c[j])
			{
				m[j]-=m[i];
				i++;
			}
			else
			{
				ans+=m[i];
				m[j]-=m[i];
				i++;
			}
		}
	}
	cout<<ans;
}
