#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
#define ll long long
ll n,m,a[N],ans[N],cnt[N],k,xiabiao[N];
void moni(ll start)
{
	k=1;
	for(int i=start;i<=n;i++)
	{
		if(cnt[a[i]])
		{
			k=xiabiao[i];
			k++;
		}
	}
}
bool check()
{
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1]) return false;
	}
	return true;
}
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		//if(m<n) break;
		cout<<ans[i]<<' ';
	}cout<<'\n';
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check() )
	{
		solve1();
		return;
	}
	for(int S=1;S<=n;S++)//di n lun 
	{
		moni(S);
	}
	//for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}
