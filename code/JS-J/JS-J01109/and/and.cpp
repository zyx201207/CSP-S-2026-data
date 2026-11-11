#include<bits/stdc++.h>
#define ll long long 
#define vet vector
using namespace std;
const int N=2e5;

int n,m;
int a[N];
bool choose[N];
int ans=1;
void dfs(int pos,int k,int cnt)
{
	if(pos>n && k>0)return ;
	if(k==0)
	{
		ans=max(ans,cnt);
		return ;
	}
	choose[pos]=1;
	dfs(pos+1,k-1,cnt&a[pos]);
	choose[pos]=0;
	dfs(pos+1,k,cnt);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(choose,0,sizeof(choose));
	scanf("%d%d",&n,&m);
	int maxn=-1;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	
	
	if(m==n)
	{
		int ans=(1<<30)-1;
		for(int i=1;i<=n;i++)ans&=a[i];
		printf("%d",ans);
		return 0;
	}
	else if(m==1)
	{
		printf("%d\n",maxn);
		return 0;
	}
	else if(m==2)
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%d",ans);
		return 0;
	}
	
	else
	{
		dfs(1,m,(1<<30)-1);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
