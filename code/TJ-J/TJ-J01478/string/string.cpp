#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int b[200005];
char c[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>c[i];
		for(int j=0;j<b[i];j++)
		{
			a+=c[i];
		}
	}
	long long h=a.size();
	long long cnt=0;
	for(int i=0;i<=h/2;i++)
	{
		if(a[i]!=a[h-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
