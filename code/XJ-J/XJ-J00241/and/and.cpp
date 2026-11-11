#include<bits/stdc++.h>
using namespace std;
int a[200005],a1[105],n,m;
string c[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
//		int cnt=0;
//		while(a[i])
//		{
//			a1[++cnt]=a[i]%2;
//			a[i]/=2; 
//		}
//		for(int j=cnt;j>=1;j--)
//		{
//			c[i]+=a1[j]-"0";
//		}
	}
	cout<<a[n];
	return 0;
}

