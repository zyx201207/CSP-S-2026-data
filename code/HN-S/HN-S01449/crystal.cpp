#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long
#define ll long long
using namespace std;
const int N = 5e5+4;
ll a[N] , b[N] ,c[N];
ll n,m;

bool check(int range)
{
	if(range > n){return 0;}
	for(int i=range; i<=n; i++)
	{
		if(c[i ] - c[i - range] <= m){return 1;}
	}
	return 0;
}






int main()
{
	IO
	freopen("crystal.in" , "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n ;i++)
	{
		cin>>a[i] ;
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++)
	{
		b[i-1] = a[i] - a[i-1];
	}
	
	n--;
	for(int i=1; i<=n; i++)
	{
		c[i] = b[n-i+1] +  c[i-1];
	}
	
	
	ll base =0, range=1;
	do
	{
		if(check(range))
		{
			base++;
			range += (1<<base);
		}
		else{
			
			range -= (1<<base);
			base--;
			if(base!=-1){range += (1<<base);}
		}
		
	}while(base!=-1&&range);
	if(base==0&&range ==1){range =-1;}
	cout<<range+1<<flush;return 0;
	
	
	
	

	
	return 0;
}
