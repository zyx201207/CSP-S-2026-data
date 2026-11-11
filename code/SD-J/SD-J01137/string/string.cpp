#include <bits/stdc++.h>
using namespace std;
long long sum[200005];
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,n,ans=0,len=0,l,r;
	char c;
	cin>>n;
	l=1,r=n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		sum[i]=sum[i-1]+a;
		ch[i]=c;
		len=sum[i];
	}
	for(long long i=1;i<=len/2;i++)
	{
		if(i>sum[l]) l++;
		if(len-i+1<sum[r]) r--;
		if(ch[l]!=ch[r]) ans++;
	}
	cout<<ans;
	return 0;
}
