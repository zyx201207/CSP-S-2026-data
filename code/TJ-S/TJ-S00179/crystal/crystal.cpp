#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10001];
int answer=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1); 
	int ans,ans1;
	for(int i=2;i<=n;i++)
	{
		ans=0;ans1=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]!=a[j])
			{
				ans+=a[i]-a[j];
				if(ans>m)
					break;
				ans1++;
			}
			if(a[i]==a[j])
				ans1++;
		}
		answer=max(ans1,answer);
	}
	cout<<answer;
	return 0;
 } 

