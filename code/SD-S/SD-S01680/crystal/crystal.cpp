#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long a[N];
//long long ch[N];
//long long qz[N];
long long n,m;
long long coun(long long x,long long y,long long c[])//x-y全部变成y所需的次数 
{
	long long num=0;
	for(int i=x;i<=y-1;i++)
	{
		num+=(a[y]-a[i]);
	}
	return num;
}
int cnt=0;
int maxn=0;
long long F(long long l,long long r)
{
	if(r>n||l>r)
	{
		return maxn;	
	} 
	if(coun(l,r+1,a)<=m)//右指针右侧还可以继续加 
	{
		r++;//右指针右移 
		F(l,r);
	}
	else
	{
		cnt=r-l+1;
		if(maxn<cnt)
		{
			maxn=cnt;
		}
		l++;
		F(l,r);	
	}	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<F(1,2);
	return 0;
}
