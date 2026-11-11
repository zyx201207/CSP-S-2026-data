#include<bits/stdc++.h>
using namespace std;

int n,m;
struct S
{
	int cnt,z,b;
}a[200005];
int r(int n,int i)
{
	int c=0;
	while(n)
	{
		if(n%2)
			a[i].cnt++;
		n/=2;
		c++;
	}
	a[i].z=c;
}
int cmp(S a,S b)
{
	return a.z>b.z;
	if(a.z==b.z)
		return a.cnt>b.cnt;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int t;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].b);
		r(a[i].b,i);
	}
	cout<<n;	
	sort(a+1,a+1+n,cmp);
	int r=a[1].b;
	for(int i=2;i<=m;i++)
	{
		r=r&a[i].b;
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
