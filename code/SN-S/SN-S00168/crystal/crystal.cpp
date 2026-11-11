#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=500005;
int n,m;
int a[maxn];
deque<int>st;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0,num=1,ans=0;
	st.push_back(n);
	for(int i=n-1;i>=1;i--)
	{
		if(cnt+a[st[0]]-a[i]<=m)
		{
			cnt+=a[st[0]]-a[i];
			st.push_back(i);
			num++;
			//cout<<i<<" "<<num<<endl;
			//ans=max(ans,num);
			//cout<<num<<endl;
		}
		else
		{
			ans=max(ans,num);
			while(cnt+a[st[0]]-a[i]>m)
			{
				num--;
			    cnt-=num*(a[st[0]]-a[st[1]]);
			    st.pop_front();
			}
			cnt+=a[st[0]]-a[i];
			st.push_back(i);
			num++;
			//ans=max(ans,num);
		}
	}
	ans=max(ans,num);
	cout<<ans;
	return 0;
}
