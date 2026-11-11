#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(c[i]==c[i-1])
		{
			cnt++;
		}
	}
	if(cnt==n-1)
	{
		cout<<0;
		return 0;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	string h;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		h=a[i]*c[i]+a[i-1]*c[i-1];
	}
	
	int len=h.size();
	int l=1,r=len;
	for(int i=1;i<=len;i++)
	{
				
		if(h[len/2+1-i]!=h[len/2+1+i])
		{
			ans++;		
		}		
		
	}
	cout<<ans;
	return 0;
}

