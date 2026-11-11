#include<bits/stdc++.h>
using namespace std;
long long n,m,x[500002],maxn=1,sum=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>x[i];
	sort(x,x+n);
	for(int i=1;i<n;i++)
	{
		sum+=(x[i]-x[i-1])*maxn;
		if(sum<=m)maxn++;
		else break;
	}
	
	cout<<maxn<<endl;
	return 0;
} 
