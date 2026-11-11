#include<bits/stdc++.h>
using namespace std;
const int N=200050;
int n,m;
long long a[N],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(a[i],ans);
	}
	if(m==1)
	{
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
