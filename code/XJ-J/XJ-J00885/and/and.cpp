#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int MAXN=200005;
long long a[MAXN];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	long long t[m+5]={0};
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	long long num=0;
	long long k=m;
	while(m--)
	{
		int maxx=0;
		for(long long i=1;i<=n;++i)
		{
			if(num==0&&a[i]>maxx) maxx=a[i]; 
			if(num>0&&a[i]>maxx&&a[i]<t[num]) maxx=a[i];
		}
		t[++num]=maxx;
	}
	cout<<t[m];
	return 0;
}