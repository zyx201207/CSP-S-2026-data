#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	int n,m,a[100005],p,q=999999;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	p=a[1]; 
	for(int i=1;i<=n;i++)
	{
		if(a[i]>p) p=a[i];
		if(a[i]<q) q=a[i];
	} 
	cout<<p-q;
	return 0;
}
