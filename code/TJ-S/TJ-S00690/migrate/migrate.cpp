#include <iostream>
using namespace std;

int a[100005];
int max_num = 0;
int dfs(int n,int m,int a[],int i,int leijia)
{
	if(i >= n)
	{
		max_num = max(max_num,leijia);
		return max_num;
	}
	
	for(int j = i;j<=i+m;j++)
	{
		dfs(n,m,a,i+=j,leijia++);
	}
}

void ans()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	cout<<dfs(n,m,a,1,0);
	
	for(int i = 1;i<=n;i++)
	{
		a[i] = 0;
	}
	max_num = 0;
	
	return;
}


int main()
{
	int c,t;
	cin>>c>>t;
	
	for(int i = 1;i<=t;i++)
	{
		ans();
	}
	
	
	return 0;
}
