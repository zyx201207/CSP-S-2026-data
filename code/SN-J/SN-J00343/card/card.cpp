#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005],b[500005],ans,cnt,cnt2,ans2;
string sb;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+1;
		cin>>b[i];		
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;i++)
		{
			if(b[j]==1)
			{
				cnt++;
				break;
			}
		}
		for(int j=i;j<=n;i++)
		{
			if(b[j]==2)
			{
				ans++;
				break;
			}
		}
		
	}
	printf("%d%d",cnt,ans);
	
}
