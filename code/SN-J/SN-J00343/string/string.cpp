#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b,ans;
char c[100000005];
string sb;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<=a[i];j++)
		{
			b++;
			if(j==1)cin>>c[b];
			else c[b]=c[b-1];
		}		
	}	
	for(int i=1;2*i<=b;i++)
	{
		if(c[i]!=c[b-i+1])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	
	
}
