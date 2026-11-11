#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[500005],cnt[300005],copy1[500005];
bool flaga=1;
int main()//I believe I will get 1=!!!
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]<=a[i-1])
			flaga=0;
	if(flaga)
		for(int i=1;i<=n;i++)
			cout<<i<<' ';
	else
	{
		for(int lun=1;lun<=n;lun++)//轮 
		{
			for(int j=1;j<=n;j++)//Copy
				copy1[j]=a[j];
			for(int i=lun;i<=n;i++)//枚举 
			{
				for(int j=i+1;j<=n;j++)//模拟
				{
					if(copy1[i]==copy1[j])
					{
						for(int k=i;k<=j;k++)
						{
							copy1[k]=0;
						}
					}
				}
			}
			for(int i=1;i<=n;i++)
				if(copy1[i]!=0)
					cnt[copy1[i]]++;
		}
		for(int i=1;i<=m;i++)
			cout<<cnt[i]<<' ';
	}
	return 0;
}
/*
思路：
模拟轮，每轮从i到n枚举，遇到相同的删除其中一个并把中间删除. 
*/
