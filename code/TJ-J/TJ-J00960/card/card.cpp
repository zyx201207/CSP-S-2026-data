#include<bits/stdc++.h>
using namespace std;
int arr[500001];
int cnt[300001];//ÊýÁ¿1,2,3...m
int lie[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>> n>>m;
	for(int i =0;i<n;i++)
	{
		cin>> arr[i];
	}
	for(int e = 0;e<n;e++)
	{
		int h = 0;
		for(int i =e;i<n;i++)
		{
			for(int j =0;j<h;j++)
			{
				if(lie[j]==arr[i])
				{
					h=j;
					break;
				}
			}
			lie[h++]=arr[i];
		}
		for(int i = 0;i<h;i++)
		{
			cnt[lie[i]]++;
		}
	}
	
	
	for(int i =1;i<=m;i++)
	{
		cout << cnt[i]<<" ";
	}
	return 0;
} 
