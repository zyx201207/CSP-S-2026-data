#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,a[20005],sum=0,num=0;
	char t[20005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>t[i];
		sum+=a[i];
	}
	string s="";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=t[i];
		}
	}
	for(int i=0;i<=sum/2;i++)
	{
		if(s[i]!=s[sum-i])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
