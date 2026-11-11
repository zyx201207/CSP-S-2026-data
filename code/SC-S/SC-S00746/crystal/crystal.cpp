#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
queue<int> q;
int n,m,a[N],w,mmax,cnt,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
		cnt++;
		w=w+(a[i]-mmax)*(q.size()-1);
		mmax=a[i];
		while(w>m)
		{
			int t=q.front();
			w=w-(mmax-t);
			cnt--;
			q.pop();
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}