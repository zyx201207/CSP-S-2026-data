#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long x[200005];
string s[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	sort(x+1,x+n+1,greater<long long>()); 
	cout<<x[m];
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
