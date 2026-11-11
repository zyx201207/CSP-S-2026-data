#include<bits/stdc++.h>
using namespace std;
int maxn=0;
int a[1000010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	cout<<maxn;
}