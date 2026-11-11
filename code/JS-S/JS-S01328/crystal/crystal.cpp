#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll m;
ll a[500050];
//sliding window?!
//expected: 100
//finished in 14:40, used 10mins
ll m_left;
ll selected;
ll lb,rb;
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	m_left=m;
	lb=1,rb=1;
	selected=1;
	for(int i=2;i<=n;i++)
	{
		m_left-=selected*(a[i]-a[i-1]);
		selected++;
		rb++;
		while(m_left<0)
		{
			m_left+=(a[i]-a[lb]);
			lb++;
			selected--;
		}
		ans=max(ans,selected);
	}
	cout<<ans<<endl;
	return 0;
}
