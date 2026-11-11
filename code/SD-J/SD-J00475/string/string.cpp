#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=1e1+10;
int n,sum;
pair<int,char>a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	for(int i=1,j=n,cntl=0,cntr=0;i<j;)
	{
		if(a[i].second==a[j].second)
		{
			int x=a[i].first-cntl,y=a[j].first-cntr;
			if(x==y)
			{
				cntl=0;
				cntr=0;
				i++;
				j--;
			}
			else if(x>y)
			{
				cntl+=y;
				cntr=0;
				j--;
			}
			else
			{
				cntr+=x;
				cntl=0;
				i++;
			}
		}
		else
		{
			int x=a[i].first-cntl,y=a[j].first-cntr;
			if(x==y)
			{
				sum+=x;
				cntl=0;
				cntr=0;
				i++;
				j--;
			}
			else if(x>y)
			{
				sum+=y;
				cntl+=y;
				cntr=0;
				j--;
			}
			else
			{
				sum+=x;
				cntr+=x;
				cntl=0;
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}

