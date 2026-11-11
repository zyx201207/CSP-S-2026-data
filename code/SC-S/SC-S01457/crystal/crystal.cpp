#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
#define int long long
#define endl '\n'
using namespace std;
int N,M,A[500005],sum[500005],ans;
map<int,int> mp;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
		mp[A[i]]++;
	}
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++)
	{
		sum[i]=sum[i-1]+A[i];
	}
	for(int i=1;i<=N;i++)
	{
		if(A[i]!=A[i-1])
		{
			int l=0,r=i-1,res=N;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if((i-1-mid)*A[i]-sum[i-1]+sum[mid]<=M)
				{
					res=mid;
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			ans=max(ans,mp[A[i]]+i-1-res);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
Name: 
Copyright: 
Author: The Pioneer,The Concluder 
Date: 18/08/26 10:10
Description: 
*/
/*
不挂分的话应该是100+64+40+15
估摸着1=应该是有了,7J不知道
这次的题非常具有思维美感,后面忘了
这键盘，鼠标还有凳子都一言难尽啊(男人叹气声
还有我要上迷惑行为大赏
以及提前 NOIP rp++
luogu uid:1235828 求关
祝我好运 /笑

*/