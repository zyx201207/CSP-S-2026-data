#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],len,cnt;
string s;
string c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
		len+=a[i];
	}
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}