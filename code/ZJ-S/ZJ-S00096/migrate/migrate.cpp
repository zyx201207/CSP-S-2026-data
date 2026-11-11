#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{//分组处理 
		int n;
		long long d;
		cin>>n>>d;
		long long x[2000001];
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		int sum=0;//sum为双径岛屿对数量 
		for(int u=1;u<=n-2;u++)
		{
			for(int v=u+2;v<=n;v++)
			{
				long long a=1,b=1,c1=v,d1=u;//a,b分别为两路径长度 
				//c1,d1为路径一初次降落的岛屿和最后降落的岛屿
				for(int j=u+1;j<=v;j++)
				{
					if(x[j]-x[d1]>d)
					{
						a++;
						if(a==2)c1=j-1;
						else d1=j-1;
					}
				}
				long long c2=u,d2=v;//逆向推导路径二 
				//c2,d2为路径二初次降落的岛屿和最后降落的岛屿 
				for(int j=v;j>=u+1;j++)
				{
					if(x[d2]-x[j]>d)
					{
						b++;
						if(b==2)d2=j+1;
						else c2=j+1;
					}
				}
				
				
				
				
				//判断是否有第三条最短路径，有则跳过本次循环 
				if(a==b && (c1!=d2 || d1!=c2))sum++;
				//确认两路径是否相同，不相同则双径岛屿对数量加一 
			}
		}
		cout<<sum<<endl;//输出该组结果 
	}
	return 0;
}
