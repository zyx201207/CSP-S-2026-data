#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,m,a[N],ans;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n==0||m==0)
	{
		cout<<"0";
		return 0;
	}
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(long long i=2;i<=m;i++)
		ans&=a[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//°´Î»Óë     &
