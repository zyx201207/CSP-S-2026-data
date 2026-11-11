#include <bits/stdc++.h>
using namespace std;
bool hmp(int x,int y,)
{
	return x>y;
}
int main()

{
	lomg lomg n,m;
	int n,m;
	cin>>n>>m;
	int a[200010];
	for(int i=1;i<=n;i++)
	{
		    cin>>a[i];
		    
	}
	sort(a+1,a+n+1,hmp)
	longlong sum=a[1];
	for(longlong i=2;i<=m;i++)
	{
		sum&=a[i]
	}
}   cout <<sum

    return 0;


