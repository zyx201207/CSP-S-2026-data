#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
long long l;
char gel(int x)
{
	long long cnt=0;
	int k=1;
	while(cnt<x)
	{
		cnt+=(a[k++]);
	}
	return c[k-1];
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l+=a[i];
		cin>>c[i];		
	}
	int ans=0;
	for(int i=1;i<=l/2;i++)
	{
		if(gel(i)!=gel(l-i+1))
		{
			ans++;
		} 
	}
	cout<<ans;
	return 0;
}
