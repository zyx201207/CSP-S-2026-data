#include<bits/stdc++.h>
using namespace std;
const int N=1e7+999999;
string a;
long long ans,n,cnt,x,cntt;
long long s[N],ss[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		cin>>a;
		cnt+=x;
		for(int j=cnt-x;j<cnt;j++)
		{
			s[j]=a[0]-'0';
		}
	}
	cntt=cnt;
	for(int i=0;i<cnt;i++)
	{
		cntt--;
		ss[cntt]=s[i];
	}
	for(int i=0;i<cnt;i++)
	{
		if(s[i]!=ss[i])
		{
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
