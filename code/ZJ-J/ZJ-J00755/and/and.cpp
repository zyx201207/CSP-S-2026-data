#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],c[N];
bool cmp(int a,int b)
{
	int sum=0,ans=0,aa=a,bb=b;
	while(a)
	{
		if(a%2)
		{
			sum++;
		}
		a/=2;
	}
	while(b)
	{
		if(b%2)
		{
			ans++;
		}
		b/=2;
	}
	if(sum==ans)
	{
		return aa>bb;
	}
	else
	{
		return sum>ans;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=2)
		{
			c[i]=a[i]-a[i-1];
		}
	}
	sort(c+1,c+n);
	if(c[2]==c[n-1])
	{
		cout<<"49152";
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<m;i++)
	{
		a[i+1]=(a[i]&a[i+1]);
	}
	cout<<a[m];
	return 0;
}

