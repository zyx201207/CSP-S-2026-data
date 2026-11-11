#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010]={0};
int b[100000010]={0};
long long ma=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1)cout<<ma;
	else if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			b[a[i]]++;
		}
		for(int i=ma;i>=0;i--)
		{
			if(b[i]>=2)
			{
				cout<<i;
				break;
			}
		}
	}
	
	
	return 0;
}