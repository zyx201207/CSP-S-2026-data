#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a,f[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		f[i]=log2(a+1)-1;
	}
	sort(f+1,f+n+1,cmp);
	cout<<f[m];
	return 0;
}
