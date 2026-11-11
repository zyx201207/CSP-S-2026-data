#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int q=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		q=max(q,a[i]);
	}
	cout<<q;
	return 0;
}