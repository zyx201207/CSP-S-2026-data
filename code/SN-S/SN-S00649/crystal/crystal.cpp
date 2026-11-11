#include<bits/stdc++.h>
using namespace std;
int a[500005], b[500005];
int n,m,num=0;
int bool1(int m,int wei)
{
	int x1 = int(wei+0.5+sqrt((2*wei+1)*(2*wei+1)-8*m));
	int x2 = int(wei+0.5-sqrt((2*wei+1)*(2*wei+1)-8*m));
	if(x1<=n && x1>0) return x1;
	if(x2<=n && x2>0) return x2;
}
int bool2(int m,int cha)
{
	int x1 = ((2-cha) + sqrt(cha*cha+8*m)) / 2.0;
	int x2 = ((2-cha) - sqrt(cha*cha+8*m)) / 2.0;
	if(x1<=n && x1>0) return x1;
	if(x2<=n && x2>0) return x2;
}
int q(int i,int m)
{
	if(a[i]<=m)
	{
		m-=a[i];
		num++;
		return q(i-1,m);
	}
	else return num;
}
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool b1=true,b2=true;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		if(a[i]!=i)
		{
			b1=0;
		}
	}
	if(b1) 
	{
		cout<< bool1(m,a[n]);
		return 0;
	}
	sort(a+1,a+1+n);
	b[1] = a[1];
	int c=b[1];
	for(int i = 2;i <= n;i++) 
	{
		b[i] = a[i]-a[i-1];
		c=b[i];
		if(b[i]!=b[i-1]) b2=0;
		
	}
	if(b2)
	{
		cout << bool2(m,c);
		return 0;
	}
	int maxx = -1;
	for(int i = n-1;i >= 1;i--)
	{
		num=0;
		int s = q(i,m);
		maxx = max(maxx,s);
	}
	cout << maxx;
	return 0;
}
