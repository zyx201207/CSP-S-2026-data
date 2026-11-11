#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int a[N];
string c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		for (int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int su=0;
		for (int i=0;i<sum/2;i++)
		{
			if (s[i]!=s[sum-i-1])
			{
				su++;
			}
		}
		cout<<su;
	return 0;
}
//ты╪Ш~ 
