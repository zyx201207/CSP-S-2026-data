#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 25;

long long n,cmax = -99999999,csum;
long long m,a[N],cha[N];

bool cmp1(int a,int b)
{
	return a < b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i ++)
	{
		cin >> a[i] ;
		
	}
	sort(a + 1,a + n + 1,cmp1);
	for(long long i = 2;i <= n;i ++)
	{
		cha[i] = a[i] - a[i - 1];
	}
	long long l = 1,r = 2,lm,rm;
	while(r <= n)
	{
		csum += (cha[r]*(r - l));
		if(r - l > cmax) 
		{
			cmax = r - l;
			lm = l;
			rm = r;
		}
		while(csum > m)
		{
			csum -= a[r] - a[l];
			l ++;
		}
		r ++;
	}
	cout << cmax << endl;
	return 0;
}
