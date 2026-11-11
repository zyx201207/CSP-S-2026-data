#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt;
int a[200005];
string s,c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)
		{
			s+=c;
		}
		
		ans+=a[i];
	}
	cout<<s;
	for(int i=0;i<ans/2;i++)
	{
		if(s[i]!=s[n-i])
		{
			cnt+=1;
		}
	}
	cout<<cnt;
	return 0;
}
