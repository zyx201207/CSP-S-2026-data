#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],sum,k;
int bfs(int num1,int num2)
{
	long long b[200010]={0},v[200010]={0},num=1,t=0;
	b[num]=num1;
	v[num]=1;
	for(int i=1;i<=num;i++)
	{
		if(t!=0)
		{
			if(v[i]==t&&v[i+1]!=t)
				return 1;
			else
				return 0;
		}
		if(a[num2]-a[b[i]]<=d)
		{
			t=v[i];
			continue;
		}
		while(a[b[num]+1]-a[b[i]]<=d&&v[num+1]==0&&num<num2-num1+1)
		{
			num++;
			b[num]=b[num-1]+1;
			v[num]=v[i]+1;
		}
	}
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)	
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			k=0;
			for(int j=i+1;j<=n;j++)
			{
				if(bfs(i,j)==1)
				{
					k=1;
					sum++;
				}
				else
					k=0;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}