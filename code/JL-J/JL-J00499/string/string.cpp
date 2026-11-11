#include <bits/stdc++.h>
using namespace std;
int n;
string c[200005];
int a[200005];
string s;
int sum[200005];
int fmx=-1e9;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		fmx=max(fmx,a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	if(n<=2e5 && fmx<=50)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=c[i];
			}
			
		}
		s=" "+s;
		int len=sum[n]/2;
		int flag=0,pos=0;
		for(int i=1;i<=n;i++)
		{
			if(sum[i]>len && sum[i-1]==len)
			{
				flag=0;
				break;
			}
			if(sum[i]>len && sum[i-1]<len)
			{
				flag=1;
				pos=i;
				break;
			}
		}
		int cnt=0;
		for(int i=1;i<=len;i++)
		{
			if(s[i]==s[sum[n]-i+1])
			{
				cnt++;
			}
		}
		cout<<len-cnt;
		return 0;
	}

}