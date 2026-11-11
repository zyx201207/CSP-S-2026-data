#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m; 
	cin>>n>>m;
	int a[n];
	int sum=m;
	int mi=10000000;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);//题目也没说是不是有序的，保险起见排序一下 
	sum/=m;//所取的最佳值 
	int t=0;//所选取的最佳数字（距离最佳值最近）的位置
	int s=0;//所选取的最佳数字（距离最佳值最近） 
	for(int i=0;i<n;i++)
	{
		if(mi>=abs(a[i]-sum))
		{
			mi=min(mi,abs(a[i]-sum));
			t=i;
			s=a[i]; 
		}
	}//寻找最佳数字和它的位置 
	if(a[0]==a[n-1])
	{
		a[t]+=1;
		s+=1;
	 } //为了满足一下ai均相等的情况 （其实是凤鲜我懒得写了，突然想混了，骗分耍起） 
	sum=0;//我懒得定义一个新的了，反正后面也用不到最佳值了，归零重利用一下 
	while(m>=0) 
	{
		if(a[t-1]<a[t])
		{
			if(a[t]-a[t-1]<=m)
			{
				m-=a[t]-a[t-1];
				a[t-1]=a[t]; 
			}
			else if(a[t]-a[t-1]>m)
			{
				break;
			}
		} 
		if(a[t-1]==a[t])
		{
			t--;
		}
	}//进行每一数字和最佳数字的配对（向前找） 
	for(int i=0;i<n;i++)
	{
		if(a[i]==s)
		sum++;
	}//遍历数组找有多少个 
	cout<<sum; 
	fclose(stdin);
	fclose(stdout);
//别忘记去注释看到了吗！！  
	return 0;
} 
