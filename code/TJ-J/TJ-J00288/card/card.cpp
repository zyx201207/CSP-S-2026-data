#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
			t[a[j]]++;
		for(int j=1;j<=n;j++)
			if(t[a[j]]>i)
				t[a[j]]=i;
	}
	for(int i=1;i<=m;i++)
		cout<<t[i];
		
		
		 
	return 0;
}
