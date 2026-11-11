#include<bits/stdc++.h>
using namespace std;
int n,middle,x,y;
long long t;
int a[100005];
char b[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	x=1,y=n;
	if (n%2==1) middle=n/2+1;
	else middle=n/2;
	for (int i=1; i<=n; i++)
		scanf("%d%s",&a[i],&b[i]);
	while(x<y)
	{
		if (a[x]==a[y])
		{
			if (b[x]!=b[y]) t+=a[x];
			x++,y--;
		}
		if (a[x]>a[y])
		{
			if (b[x]!=b[y]) t+=a[y];
			a[x]-=a[y],y--;
		}
		if (a[x]<a[y])
		{
			if (b[x]!=b[y]) t+=a[x];
			a[y]-=a[x],x++;
		}
	}
	cout<<t;
	return 0;
}
