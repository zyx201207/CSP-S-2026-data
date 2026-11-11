#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],j,ans;
char s[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	j=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=j;i++)
	{
		while(j>=i&&a[i]>=a[j])
		{
			a[i]-=a[j];
//			a[j]=0;
			if(s[i]!=s[j])
			{
				ans+=a[j];
			}
			else
			{
				a[j]=0;
			}
			a[j]=0;
			j--;
		}
		if(s[j]!=s[i]&&a[i]<a[j])
		{
			a[j]-=a[i];
			ans+=a[i];
			a[i]=0;
			
		}
		else if(s[j]==s[i])
		{
			a[j]-=a[i];
			a[i]=0;
		}
	}
	cout<<ans;
	return 0; 
 } 
 /*
 3
2 a
2 b
1 c
*/
