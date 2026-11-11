#include<bits/stdc++.h>
using namespace std;

long long n,m,js;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i) js++;
	}
	if(js==n)//上等等差数列。
	{
		long long ans=0;
		for(int i=n;i>=1;i--)
		{
			if(m<(a[n]-a[i])) 	break;
			m=m-(a[n]-a[i]);
			ans++;
		}
		cout<<ans;
		return 0;
	}
	long long g=a[2]-a[1];
	js=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=g)
		{
			js=1;
			break;
		}
	}
	if(js==0)//差一点的等差数列
	{
		long long ans=0;
		for(int i=n;i>=1;i--)
		{
			if(m<(a[n]-a[i])) 	break;
			m=m-(a[n]-a[i]);
			ans++;
		}
		cout<<ans;
		return 0;
	} 
	sort(a+1,a+n+1);
	long long maxv=-1e18;//答案。 
	long long w,j,k,ans=0;//w代替 m参与运算 ,j为第一个比i小的a数组中的编号，向左跑，ans计数，从零开始。 
	for(long long i=a[n];i>a[1];i--)//为倒序，因为从小到大排序。 
	{//枚举i为不变数值。即全部向i靠拢。 
		//当i小于等于a[1]时，i不能为 不变数值，因为 i小于等于最小值。直接接入循环判断。 
		//i==a[n]无需特殊判定。 
		j=upper_bound(a+1,a+n+1,i)-a-1;//现在，j为 a数组中第一个大于i的编号。
	/*	while(1<2)
		{//j必须为第一个a数组中的比i小的元素的编号。 
			if(a[j]<i) break;//a[j]等于小于i时，退出循环，开始常规操作。  
			j--;
		}*/
	//	cout<<i<<" "<<j<<" "<<a[j]<<" ";//检验i,j,a[j]的值。 
		w=m,ans=0;
		while(1<2)
		{//开始常规操作。 
			if(j==0) break;//碰壁，停止操作。 
			if(w-(i-a[j])<0) break;//w不足以支持操作，退出循环。 
			w=w-(i-a[j]);//w进行操作，减去差值。 
			ans++,j--;//计数器+1，变化左移。 
		}
	//	cout<<ans<<endl;
		maxv=max(maxv,ans);//判断大小。 
		if(j==0&&w>0) break;//在已经碰壁在情况下，若m没用完，则i不可能为最优解。 
	}
	cout<<maxv;
	/*
	10 10
	1 4 6 7 7 8 2 8 9 20
	*/
	/*
	5 8
	-3 -1 2 2 7
	*/
	return 0;
}
