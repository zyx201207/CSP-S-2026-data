#include<bits/stdc++.h>
using namespace std;
int n;
long long int m,a[200020],t1,t2,sum1[200020],sum2[200020],t3,t4;
long long int cnt;
char c[200020];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		m=m+a[i];
		sum1[i]=m;
//		for(int j=1;j<=a[i];j++)
//		{
//			s=s+c[i];
//		}
	}
	for(int i=n;i>=1;i--)
	{
		sum2[i]=sum2[i+1]+a[i];
	}
	if(n<=2)
	{
		if(n==1) cout<<"0"<<endl;
		if(n==2)
		{
			if(c[1]==c[2]) cout<<"0"<<endl;
			else cout<<(min(a[1],a[2]))<<endl;
		}
		return 0;
	}
	t1=1;
	t2=n;
	for(int i=1;i<=n;i++)
	{
		if(t1>=t2) break;
		if(a[t1]==a[t2])
		{
			if(c[t1]!=c[t2]) cnt=cnt+a[t2];
			t1++;
			t2--;
			continue;
		}
		if(a[t1]<a[t2])
		{
			if(c[t1]!=c[t2]) cnt=cnt+a[t1];
			a[t2]=a[t2]-a[t1];
			t1++;
		}
		else
		{
			if(c[t1]!=c[t2]) cnt=cnt+a[t2];
			a[t1]=a[t1]-a[t2];
			t2--;
		}
	}
	cout<<cnt<<endl;
}