#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],b[N],l=1,r=1,sum,ans;
void work();
void output();
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
}
void work()
{
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		r++;
		sum+=(a[i]-a[i-1])*(r-l-1);
		while (sum>m)
		{
			sum-=a[i]-a[l];
			l++; 
		}
		ans=max(ans,r-l);
	}
}
void output()
{
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input();
	work();
	output();
	return 0;
}

