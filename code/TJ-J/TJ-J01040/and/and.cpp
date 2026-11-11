#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],f[200005];
const int MAX=2147483647;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m ;
	bool t1=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] ;
	}
	f[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(j==1)
			{
				f[j]=max(f[j],a[i]);
			}
			else f[j]=max(f[j],max(f[j], f[j-1]&a[i] ));
			//cout << f[m] << ' ' ;
		}
	}
	cout << f[m] ;
	return 0;
}
