#include<bits/stdc++.h>
#define int long long
using namespace std;
const signed N=5e5+5;
int n,m,a[N],ans,res,cnt;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	//先跑一遍以a[n]为目标的
	res=m;
	for(int i=n; i>=1; i--)
	{
		if(res>=(a[n]-a[i]))
		{
			res-=(a[n]-a[i]);
			cnt++;
		}
		else break;
	}
	ans=max(ans,cnt);
	for(int i=n-1; i>=1; i--)
	{
		if(i<=ans)break;//小优化 
		cnt--;
		if(a[i]==a[i+1])continue;
		else
		{
			//每个数应多出的操作个数*总共多出的数
			res+=(a[i+1]-a[i])*cnt;
			for(int j=i-cnt; j>=1; j--)//往前面填充 
			{
				if(res>=(a[i]-a[j]))
				{
					res-=(a[i]-a[j]);
					cnt++;
				}
				else break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	/*
	发现
	既然比i大的数又不能减小
	那当a[i]=i时
	且i+1≠a[i+1]时
	我为何要让i+1去给每个之前已经被草果的数再浪费一次操作呢
	以此把外层max_a优化到了n
	*/
	return 0;
}
/*
5
1 2 4 8 9 
目标：8
cnt：1
res：5
ans:2
*/
