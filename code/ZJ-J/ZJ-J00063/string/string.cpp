#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+15;
int n;
int len[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>len[i]>>c[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=1,j=n;i<j;)
	{
		int xa=len[i];
		int xb=len[j];
		char ca=c[i];
		char cb=c[j];
		if(ca!=cb) cnt+=min(xa,xb);
		if(xa==xb)
		{
			i++;
			j--;
		}
		if(xa>xb)
		{
			len[i]-=len[j];
			j--;
		}
		if(xa<xb)
		{
			len[j]-=len[i];
			i++;
		}
	}
	cout<<cnt;
	return 0;
}