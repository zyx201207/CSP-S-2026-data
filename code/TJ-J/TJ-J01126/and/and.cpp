#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005],num=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				b[num]=(a[i]&a[j]);
			    num++;
			}
		}
	}
	sort(b+1,b+num+1);
	cout<<b[num];
	return 0;
}
