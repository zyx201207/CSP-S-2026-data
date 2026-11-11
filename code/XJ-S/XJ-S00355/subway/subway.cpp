#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q,flag;
struct node
{
	long long int ktot,tintotai[25],flag,f[25],did,line,minn=3213122312;
};
node f[505];
long long int wo_diu_lei_lao_mou(long long int begin,long long int end)
{
	int line=-1;
	if(f[begin].did==1)
		return -1;
	
	for(int i=0;i<n;i++)//线路循环 
	{
		for(int j=0;j<n;j++)//寻找同线站台 
		{
			for(int k=0;k<n;k++)//每j的站台的线路循环
			{
				if(f[j].tintotai[j]==f[begin].tintotai[i])
				{
					f[begin].did=1;
					return wo_diu_lei_lao_mou(j,end);
				}
			}
		}
	}
}
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>f[i].ktot;
	}
	for(int i=0;i<n;i++);
	{
		int diu;
		cin>>diu;
		for(int j=0;j<diu;j++)
		{
			int x,y;
			cin>>x>>y;
			f[x].tintotai[j]=y;
			f[x].flag++;
		}
	}
	for(int i=0;i<q;i++)
	{
		int begin,end;
		cin>>begin>>end;
		wo_diu_lei_lao_mou(begin,end);
	}
	
}
