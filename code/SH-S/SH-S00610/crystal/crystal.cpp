//球了啊我想上HEFZ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());
	queue<int> q;
	int sum=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		q.push(nums[i]);
		sum+=nums[i];
		while(q.size()*nums[i]-sum>m)
		{
			sum-=q.front();
			q.pop();
		}
		ans=max(ans,(int)(q.size()));
	}
	cout<<ans;
	return 0;
}
