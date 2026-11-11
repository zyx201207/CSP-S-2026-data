#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],c,d=0,e,f=0,n;
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1]>>ch[1];
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		b[i]=b[i-1]+a[i];
	}
	c=b[n];
	e=n;
	for(int i=1;i<=(c+1)/2;i++)
	{
		int j=c+1-i;
		if(i>b[d])
		{
			d++;
		}
		if(b[e-1]>=j)
		{
			e--;
		}
		if(ch[d]!=ch[e])
		{
			f++;
		}
	}
	cout<<f;
	return 0;
}
