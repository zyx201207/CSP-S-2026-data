#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	int cnt=a[1];
	for(int i=2;i<=m;i++)
	{
		cnt=cnt&a[i];
	}
	cout<<cnt;
	return 0;
}
