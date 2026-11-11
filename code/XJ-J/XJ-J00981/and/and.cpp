#include<bits/stdc++.h>
using namespace std;
long long a[200005],s=-1,t,b[200005];
long long n,m,i,j;
//void f(long long x)
//{
//	t=b[x];
//	if((x+1)>m) return;
//	for(i=x+1;i<=n-x;i++)
//	{
//		if(x==0) t=a[i];
//		else t=t and a[i];
//		b[x]=t;
//		if((x+1)==m) 
//		{
//			if(t>s) s=t;
//		}
//	}
//	f(x++);
//	return;
//}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>t) t=a[i];
	}
//	f(0);
	if(m==2)
	{
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{	
				if((a[i]&a[j])>s) s=a[i]&a[j];
			}
		}
		cout<<s;
		return 0;
	}
	cout<<t;
	return 0;
}