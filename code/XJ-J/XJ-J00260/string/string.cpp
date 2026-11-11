#include<bits/stdc++.h>
using namespace std;
long long n,x,y,a[200005],b[200005],cnt=0,ans=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];
		b[i]=cnt;
	}
	long long l=1,r=cnt;
	while(l<r)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j]>=l&&b[j-1]<l) x=c[j];
			if(b[j]>=r&&b[j-1]<r) y=c[j];
		} 
		if(x!=y) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
} 
