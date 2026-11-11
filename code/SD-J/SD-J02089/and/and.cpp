#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],x[100010];
string s;
void zh(int n)
{
	int cnt=0;
	while(n!=0)
	{
		a[cnt++]=n%2;
		n/=2;
	}
	for(int i=cnt-1;i>=0;--i)
		for(int j=0;j<cnt;++j)
			b[j]=a[i];
//	for(int i=0;i<cnt;++i)
//		cout<<a[i];
}
int main()
{
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i];
		zh(x[i]);
		cout<<max(x[i]&x[i-1]);
	}
	
	return 0;
}
