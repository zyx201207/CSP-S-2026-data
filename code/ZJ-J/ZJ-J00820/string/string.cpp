#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005],ao[200005];
char c[200005],co[200005];
long long len=0,maxx=0;
char s[200005],so[200005];
int top=0;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
		maxx=max(maxx,(long long)a[i]);
		if(len>200000)flag=0;
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)s[top+j]=c[i];
			top+=a[i];
		}
		for(int i=1,j=top;i<j;i++,j--)
			if(s[i]!=s[j])ans++;
		cout<<ans;
		return 0;
	}
	else if(maxx==1)
	{
		for(int i=1,j=n;i<j;i++)
			if(c[i]!=c[j])ans++;
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=1,j=1;s[i]*2<=len&&s[j]*2<=len;)
		{
			long long l=s[i-1]+1,r=s[i];
			long long L=so[j-1]+1,R=so[j];
			long long chong=max((long long)0,r-L+1);
			if(c[i]!=co[i])ans+=chong;
			if(r<R)i++;
			else j++;
		}
		cout<<ans;
	}
	return 0;
}
