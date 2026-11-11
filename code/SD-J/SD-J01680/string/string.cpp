#include<bits/stdc++.h>
using namespace std;

int n;
string s;
long long len;
void xiu()
{
	long long ans=0;
	long long r=len-1;
	long long mid=len/2;
	for(long long l=0;l<mid;l++)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		r--;
	}
	printf("%lld",ans);
	return;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		scanf("%d ",&x);
		c=getchar();
		for(int j=1;j<=x;j++) 
		{
			s+=c;
		}
		len+=x;
	}
	xiu();
	return 0;
}

