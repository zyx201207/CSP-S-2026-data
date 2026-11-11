#include<iostream>
using namespace std;
using i64=long long;
const int N=2e6+5;
int n;
i64 d,a[N];
void solve(int id)
{
	cin>>n>>d;
	i64 last=0,micha=1e18;//…œ“ª¥Œ≤Ó 
	bool flag1=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (i>2 && a[i]-a[i-1]!=last)	{flag1=0;}
		if (i>1)last=a[i]-a[i-1];
		micha=min(micha,last);
	}
	if (n<=3 || micha>d)
	{
		cout<<"0\n";
		return ;
	}
	if (flag1)
	{
		i64 ma=d/last*last;
		i64 ans=0;
		for (int i=4;i<=n;i++)
		{
			if ((i-1)*last%ma==0)	continue;
			i64 tmp=((i-1)*last)/ma;
			if (tmp==1)	ans+=n-i+1;
		}
		cout<<ans<<"\n";
		return ;
	}
	cout<<"0\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	for (int i=1;i<=t;i++)	solve(i);
	return 0;
}
/*
0 1
5 5
1 3 5 7 9
*/

