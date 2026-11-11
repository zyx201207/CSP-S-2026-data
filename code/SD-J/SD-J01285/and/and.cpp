#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool b[200005][31];
int c[31];
int uid[200005];
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int mx=0;
	for(int i=0;i<n;i++)
	{
		for(int j=30;j>=1;j--)
		{
			if(a[i]>pow(2,j))
			{
				a[i]-=pow(2,j);
				b[i][j]=1;
				c[j]++;
			}	
		} 
	}
	for(int i=30;i>=0;i--)
	{
		if(c[i]>=2)
		{
			mx=i;
		}
	}
	int t=0;
	for(int j=0;j<n;j++)
	{
		if(b[j][mx]==1)
		{
			uid[t]=j;
			t++;
		}
	}
	while(t!=2)
	{
		int t1=t;
		t=0;
		for(int i=mx;i>=0;i--)
		{
			for(int j=0;j<t1;j++)
			{
				if(b[uid[j]][i]==1)
				{
					t++;
				}
			}
			if(t>=2)
			{
				for(int j=0;j<t1;j++)
				{
					if(b[uid[j]][i]!=1)
					{
						uid[j]=-1;
					}
				}
			}
		}
	}
	int ans1=0,ans2=0;
	for(int i=0;i<n;i++)
	{
		if(uid[i]!=-1&&ans1)
		{
			ans2=a[uid[i]];
			break;
		}
		if(uid[i]!=-1&&!ans1)
		{
			ans1=a[uid[i]];
		}
	}
	
	return 0;
}

