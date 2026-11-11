#include<bits/stdc++.h>
using namespace std;
int main()
{
	//孙晨阳 西安市益新中学 SN-J00720 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[100005],b[100005],maxx;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;i++)
		{
			b[i]=a[i]&a[j];
		}
	}
	maxx=b[1];
	for(int i=2;i<=n;i++)
	{
		maxx=max(maxx,b[i]);
	}
	cout<<maxx;
	return 0;
}
