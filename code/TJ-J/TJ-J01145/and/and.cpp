#include <bits/stdc++.h>
using namespace std;
int n,a[100005],c[100005],m,maxn=-1,num[100005],pooo;
string p;
int fe(int p)
{
	if (p==1) return pooo;
	pooo+=p%10*10;
	fe(p/=2);
}
int And(string m,string n)
{
	int s=max(m.length(),n.length());
	for (int i=1;i<=s-1;i++)
	{
		if (m[i]==n[i])
		{
			p+='1';
		 } 
		 else
		 {
		 	p+='0';
		 }
	 } 
	return p;
}

int main()

{
	freopen("and.in","r",stdin);
	freoprn("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	c[i]=fe(a[i]);
	}
	for (int i=1,i<=n;i++)
	{
		for (int j=i;j<=m+i;j++)
		{
		c[i+1]=And(c[i],c[i+1]);
		num=c[m+i];
	}
	maxn=max(num,maxn);
	}

	cout<<maxn;
	
	
	return 0;
}
