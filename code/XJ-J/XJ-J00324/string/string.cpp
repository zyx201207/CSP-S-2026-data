#include <bits/stdc++.h>
using namespace std;
string b,d;
char c;
int n;
long long sum1=0,sum2=0,cnt=0,minn=-1,a[200010],x;
int main()
{
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)
		{
			b+=c;
		}
		x+=a[i];
		sum1+=a[i];
		minn=min(minn,a[i]);
	}
	for(int i=1;i<=sum1;i++)
	{
		if(b[i]==b[i-1]) cnt++;
	}
	if(sum1-1==cnt) 
	{
		cout<<"0";
		return 0;
	}
	for(int i=sum1-1;i>=0;i--) d+=b[i];
	if(b==d)
	{
		cout<<"0";
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<x-a[n];
	return 0;
} 
