#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int n,m,dp[N],t,maxn;
long long int data[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>data[i];
	}
	sort(data+1,data+1+n,greater<int>());
	cout<<data[m];
	return 0;
}