#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int s[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		s[i]=a;
	}
	sort(s,s+n+1);
	cout<<s[m];
	return 0;
}
