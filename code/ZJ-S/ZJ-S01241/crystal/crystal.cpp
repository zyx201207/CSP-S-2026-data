#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=5e5+1;
int n;
ll m,a[inf];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	queue<int>q;
	ll tot=-1,cnt=0,num=0,pre=LONG_LONG_MIN;
	for(int i=1;i<=n;i++)
	{
		if(pre==a[i])num++;
		else num=0;
		if(q.empty())
		{
			pre=a[i];
			q.push(a[i]);
		}
		else
		{
			while(!q.empty()&&cnt+((ll)q.size()-num)*(a[i]-pre)>m)
			{
				int now=q.front();
				cnt-=(pre-now);
				if(now==pre)num--;
				q.pop();
			}
			cnt+=((ll)q.size()-num)*(a[i]-pre);
			q.push(a[i]);
			pre=a[i];
		}
		tot=max(tot,(ll)q.size());
	}
	tot=max(tot,(ll)q.size());
	cout<<tot;
	return 0;
}
/*
*/
