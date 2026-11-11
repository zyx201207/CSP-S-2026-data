#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
const int N=2e5+5;
int n,m;
int a[N];
long long maxx=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=m;i<=n;i++)
	{
		long long maxx_c=a[i];
		for(int j=1;j<m;j++)
		{
            maxx_c=(maxx_c&a[i-j]);
		}
		if(maxx_c>maxx) maxx=maxx_c;
	}
	cout<<maxx;
	return 0;
}
