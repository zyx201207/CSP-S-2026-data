#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
int n,t=0;
long long ans=0,l=0;
int a[N];
char r[N];
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i]>>r[i];
		while(a[i]--) s+=r[i];
	}
	int t=0;
	for (int i=0;i<(s.size()/2+s.size()%2);++i)
		if (s[i]!=s[s.size()-i-1])
			ans++;
	cout<<ans;
	
	
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
