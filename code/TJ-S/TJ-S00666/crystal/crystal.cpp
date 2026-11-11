#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];//输入数据
int ans=1,maxn=0,mm=0;//临时存放答案，最优结果，临时m 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;//输入水晶数量和操作次数
	mm=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a,a+n+1);
	//cout<<endl;
	for(int i=n;i>0;i--)//从后往前遍历，以每一个数组为基准找最大值 
	{
		ans=1,mm=m;//每次算完都要归0 
		//cout<<i<<":"<<endl;
		for(int j=i-1;j>0;j--)
		{
			if(a[j]+mm<a[i])
			{
				break;
			}	
			mm-=(a[i]-a[j]);
			//cout<<mm<<" "<<(a[i]-a[j])<<endl;
			ans++;
			//if(ans==4) cout<<a[i]<<endl; 
		} 
		if(maxn<ans)//记录最优结果 
		{
			maxn=ans;
			ans=1;
		}
	}
	cout<<maxn;
	return 0;	
 } 
