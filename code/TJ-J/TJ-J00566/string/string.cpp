#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],n,cnt;
char c[N];
string s; 
int main()
{
	freopen("string.in" "r",stdin)
	freopen("string.out" "w",stdout)
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c;
		}
	}
	
	for(int i=0,j=s.size()-1;i<=j;i++,j++)
	{
		if(s[i]!=s[j])++cnt;
	}
	cout<<cnt;
	freopen(stdin);
	freopen(stdout);
	return 0;
}
