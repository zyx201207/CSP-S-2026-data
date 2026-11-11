#include <bits/stdc++.h>
using namespace std;

int n,l,r,mid;
const int MAXN = 500005;
long long m;
long long a[MAXN];
long long pre[MAXN];

bool check(int p)
{
	for(int i=1;i+p-1<=n;i++)
	{
		if(a[i + p - 1] * (long long)p - 
		(pre[i + p - 1] - pre[i - 1]) <= m)
			return 1;
	}
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	pre[0] = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i] = pre[i-1] + a[i]; 
		//cout<<pre[i]<<" ";
		
	}//cout<<endl;
	
	
	l = 1;
	r = n;
	while(l<r)
	{
		mid = (l + r) >> 1;
		if(check(mid))
		{
			l = mid + 1;
		}else{
			r = mid;
		}
	} 
	cout<<l - 1<<endl;
	
	
	
	return 0;
}
