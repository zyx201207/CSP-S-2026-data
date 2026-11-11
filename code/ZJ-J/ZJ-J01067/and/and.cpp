#include<bits/stdc++.h>
using namespace std;
struct dt
{
	int long long num,n1;
}a[200010];
int n,m,i,j,k,l,s;
void er(int long long x1,int y1)
{
	while(x1>1)
	{
		if(x1%2==1)
		a[y1].n1++;
		x1/=2;
	}
	a[y1].n1++;
}
bool cmp(dt x,dt y)
{
	return x.n1>=y.n1;
}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].num;
		er(a[i].num,i);
	}
	stable_sort(a+1,a+n+1,cmp);
	s=a[1].num;
	for(i=2;i<=m;i++)
	{
		s=(s&a[i].num);
	}
	cout<<s;
	return 0;
}
