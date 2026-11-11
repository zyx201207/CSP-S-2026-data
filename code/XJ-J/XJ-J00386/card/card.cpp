#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N],m,n,q[N];
map<int ,int >cnt,s,c;
int f()
{
	for(int i=1;i<=n;i++)
	{
		if(c[a[i]]>1)
		{
			return 0;
		}
	}
	return 1;
}
void ta()
{
	for(int i=1;i<=m;i++)
	{
		cout<<i<<" ";
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	if(f()==1)
	{
		ta();
	}
	else
	{
		int t=1,w=1,n1=1;
		while(n1!=n)
		{
			for(int i= n1;i<=n;i++)
			{
				if(cnt[a[i]]==0)
				{
					q[t]=a[i];
				}
				else
				{
					for(int j=t;j<=w;j++)
					{
						if(q[j]==a[i])
						{
							w=j;
							break;
						}
					}
				}
			}
			for(int i=1;i<=m;i++)
			{
				s[i]+=cnt[i];
			}
			n1++;
		}	
		for(int i=1;i<=m;i++)
		{
			cout<<s[i]<<" ";
		}
	}
	return 0;
}