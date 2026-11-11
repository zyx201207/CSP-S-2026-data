#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ull maxn=1073741823;
const int N=2e5+5;

int n,m;
ull a[N];
ull ans=0;
ull mm=0;

void dfs(ull ma,int num,int i)
{
	if(num==m)
	{
		ans=max(ans,ma);
		return;
	}
	if(i>n)
	{
		return;
	}
	dfs(ma&a[i],num+1,i+1);
	dfs(ma,num,i+1);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	if(n>65536)
	{
		cout<<mm;
		return 0;
	}
	dfs(maxn,0,1);
	if(ans!=0)
	{
		cout<<ans;
	}
	else
	{
		cout<<mm;
	}
	return 0;
}
