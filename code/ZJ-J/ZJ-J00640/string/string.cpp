#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010],c[200010],s[50000010],ss[50000010];
char ch;
long long sum,ans,sum2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>ch;
		c[i]=ch-'a'+1;
		sum+=a[i];
	}	
	for(int i=1;i<=n;i++)
	{
		if(sum2+a[i]<=sum/2)
		{
			for(int j=sum2+1;j<=sum2+a[i];j++) s[j]=c[i];
			sum2+=a[i];
		}
		else if(sum2+a[i]>sum/2)
		{
			for(int j=sum2+1;j<=sum/2;j++) s[j]=c[i];
			sum2=sum/2;
		}
		if(sum2==sum/2) break;
	}
	sum2=0;
	for(int i=n;i>=1;i--)
	{
		if(sum2+a[i]<=sum/2)
		{
			for(int j=sum2+1;j<=sum2+a[i];j++) ss[j]=c[i];
			sum2+=a[i];
		}
		else if(sum2+a[i]>sum/2)
		{
			for(int j=sum2+1;j<=sum/2;j++) ss[j]=c[i];
			sum2=sum/2;
		}
		if(sum2==sum/2) break;
	}
	for(int i=1;i<=sum/2;i++)
	  if(ss[i]!=s[i]) ans++;
	cout<<ans<<endl;
	return 0;
}
