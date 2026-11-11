#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1],b[31],c[31];
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << a[n/2];
	//for(int i=1;i<=n;i++)
	//{
	//	while(a[i]<=0)
	//	{
	//		b[32-i]=a[i]%2;
	//		a[i]=a[i]/2;
	//		cout << a[i];
	//	}
	 //} 
	return 0;
 } 
