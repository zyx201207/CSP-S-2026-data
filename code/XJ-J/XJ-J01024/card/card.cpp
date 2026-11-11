#include<iostream>
#include<algorithm>
using namespace std;
long long int a[500005],n,m,s[300005],t[500005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j,k,q;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			t[a[j]]++;
			if(t[a[j]]>1)
			{
				for(k=i;k<j;k++)
				{
					if(a[k]==a[j])
					{
						q=k;
						break;
					}
				}
				if(k>=j)
				{
					for(k=q;k<j;k++)
					{
						t[a[k]]=0;
					}
					t[a[j]]++;
				}
			}
		}
		for(k=1;k<=m;k++)
		{
			if(t[m]!=0)
			{
				s[m]++;
			}
		}
		t[500005]={0};
	}
	for(i=1;i<=m;i++)
	{
		cout<<s[m]<<" ";
	}
	return 0;
}