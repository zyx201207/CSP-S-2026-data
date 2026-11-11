#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long jiec(int num)
{
	if(num==1||num==0) return 1;
	return num*jiec(--num);
}
int n,m;
long long a[N],maxx=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	long long cnt=jiec(n)/(jiec(m)*jiec(n-m));
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1) cout<<maxx;
	fclose(stdin);fclose(stdout);
	return 0;
}
