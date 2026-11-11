#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 6e5+100;
int n,m;
long long arr[MAXN];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//Step1:输入 
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>arr[i];
	}
	//Step2:排序处理
	sort(arr,arr+1+n);
	//Step3:正式处理
	int ans = 0;
	int pre = 1;//区间头
	int sz = 0;//区间长 
	long long sum = 0ll;//区间和 
	for(int i=1;i<=n;++i) 
	{
		sum += arr[i];
		sz++;
		long long delta = arr[i]*sz-sum;
		
		//可行情况 
		if(delta<=m)
		{
			ans = max(ans,sz);
		}
		else//不可行：删掉结尾一个 
		{
			long long newsum = sum-arr[pre];
			long long newdelta = arr[i]*(sz-1)-newsum;
			sum = newsum;
			pre++; 
			delta = newdelta;
			sz--;
			
		} 
		//cout<<i<<" "<<sz<<" "<<sum<<endl;
	}
	cout<<ans;
	return 0;
} 
