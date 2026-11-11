//进行至多m次 +1 操作后数列a中相同的数字最多
//求有最多多少个相同的数  
//蚌埠住了 T1没思路 
//打一个等差数列的特殊性质
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	int d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d=a[i]-a[i-1];
	}
	int cnt=(1+(sqrt(1+8*m/d)))/2;
	cout<<cnt;
	return 0;
}

