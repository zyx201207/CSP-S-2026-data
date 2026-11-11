#include<bits/stdc++.h>
using namespace std;

#define int long long

int pre[500005], a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m, ans=0, cur=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+1+n);
	for(int i=1, j=1; i<=n; i++)
	{
		m-=a[i]*(i-j)-a[i-1]*(i-j);
		cur++;
		//cout<<"curm: "<<m<<endl;
		while(m<0)
		{
			m+=a[i]-a[j];
			cur--;
			j++;
			if(cur==0)break;
		}
		if(m<0)break;
		ans=max(ans, cur);
		//cout<<cur<<" ";
	}
	cout<<ans;
	return 0;
}
