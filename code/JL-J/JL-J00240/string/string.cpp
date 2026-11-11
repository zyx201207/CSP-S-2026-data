#include<bits/stdc++.h>
using namespace std;
#define N 2000005
struct Node 
{
	long long gs;
	char ch;
}a[N];
long long n,ks,js,sum;
long long jx;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i].gs>>a[i].ch;
	}
	ks=0;
	js=n-1;
	while(ks<js)
	{
		jx=min(a[ks].gs,a[js].gs);
		if(a[ks].ch!=a[js].ch)
		{
			sum+=jx;
		}
		a[ks].gs-=jx;
		a[js].gs-=jx;
		if(a[ks].gs==0)ks++;
		if(a[js].gs==0)js--;
	}
	cout<<sum<<endl;
	return 0;
}
