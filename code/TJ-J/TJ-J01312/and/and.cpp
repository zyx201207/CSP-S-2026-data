#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],num=1048576/2,x,s[200005][22],maxn=-1,p=1,q,mm[200005];
void dfs(int x,int y)//3 15
{
	q=0;
    for(int i=1;i<=20;i++)
    {
        if(s[x][i]==s[y][i]&&s[x][i]==1)
        {
        	for(int j=1;j<=20-i;j++)
        	{
        		p*=2;
			}
			q+=p;
			p=1;
		}
    }
    return ;
}
void bfs(int ci,int k)//次数m 按位与结果 
{
	if(ci==0)
	{
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(k,i);
		bfs(ci-1,q);
	}
	if(ci==1)
	{
		maxn=max(maxn,q);
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;//4 2
	for(int i=1;i<=n;i++)//第i个数 
	{
		cin>>x;
		a[i]=x;//3 15 12 12 11 1111 1100 1100
		for(int j=1;j<=21;j++)//01 第j位数 
		{
			if(x>=num)
			{
				s[i][j]=1;
//				f=1;
				x=x-num;
			}
//			else if(f==1)
//			{
//				s[i][j]=1;
//			}
			num/=2;
//			cout<<num<<endl;
		}
//		for(int j=1;j<=20;j++)
//		{
//			cout<<s[i][j];
//		}
//		cout<<endl;
//		f=0;
		num=1048576/2;
	}
	for(int i=1;i<=n;i++)
	{
		bfs(m,i);
	}
	cout<<maxn;
	return 0;
}
