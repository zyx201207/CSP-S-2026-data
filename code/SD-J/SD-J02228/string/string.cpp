#include<bits/stdc++.h>
using namespace std;
struct node
{
	int sz;
	char c;
}a[200005];
long long n,cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sz;
		cin>>a[i].c;
	}
	long long l=1,r=n;
	while(l<r)
	{
		int minn=min(a[l].sz,a[r].sz);
		a[l].sz=a[l].sz-minn;
		a[r].sz=a[r].sz-minn;
		if(a[l].c!=a[r].c) cnt+=minn;
		if(a[l].sz==0) l++;
		if(a[r].sz==0) r--;
	}
	cout<<cnt;
	return 0;
}
