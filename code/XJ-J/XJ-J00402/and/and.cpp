#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
struct node
{
	long long num;
	long long wer;
};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		long long maxx;
		for(int i=0;i<n;i++)
		{
			maxx=max(maxx,a[i]);
		}
	}
	if(m==n)
	{
		int cnt=a[0];
		for(int i=0;i<n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	
	return 0;
}
