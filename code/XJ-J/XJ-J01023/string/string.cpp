#include<bits/stdc++.h>
using namespace std;
char c[200002],c1[100001],c2[100001];
long long a[200002];
long long ans=0,num=0,d=1;
string b;
int main()
{
	int n,m,j=1;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i] >> c[i];
	num=a[1];
	for(int i=1;i<=n;i++)
	{
		for(int k=d;k<=num;k++)
			b[k]=c[i];
		d+=a[i];
		num+=a[i+1];
	}
	if(num%2==0)
		m=num/2;
	else
		m=num/2+1;
	for(int i=1;i<m;i++)
		c1[i]=b[i];
	for(int i=num;i>m;i--)
	{
		c2[j]=b[i];
		j++;
	}
	for(int i=1;i<m;i++)
		if(c1[i]!=c2[i])
			ans++;
	cout << ans;
	return 0;
}