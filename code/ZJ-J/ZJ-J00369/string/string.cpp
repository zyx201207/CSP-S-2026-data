#include<bits/stdc++.h>
using namespace std;
long long n,ret=0;
struct node{
	long long t;
	string s;
}a[200005];
string s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t>>a[i].s;
		for(int j=1;j<=a[i].t;j++)
		{
			s1+=a[i].s;
		}
	}
	for(int i=0;i<=s1.size()/2;i++)
	{
		if(s1[i]!=s1[s1.size()-i-1])
		{
			ret++;
		}
	}
	cout<<ret;
	return 0;
} 
