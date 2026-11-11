#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int n,m;
long long ans=0;
char a[35][200005];
bool vis[200005];
long long l[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536
,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864
,134217728,268435456,536870912,1073741824};
queue<int> w;
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	memset(vis,true,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		for(int j=30;j>=0;j--)
		{
			if(x>=l[j])
			{
				a[j][i]='1';
				x-=l[j];
			}
			else
			{
				a[j][i]='0';
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=30;j>=0;j--)
//		{
//			cout<<a[j][i]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=30;i>=0;i--)
	{
		long long cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])
			{
				continue;
			}
			if(a[i][j]=='1')
			{
				cnt++;
			}
			else if(a[i][j]=='0')
			{
				vis[j]=false;
				w.push(j);
			}
		}
		if(cnt>=m)
		{
			ans+=l[i];
			cnt=0;
		}
		else
		{
			cnt=0;
			while(!w.empty())
			{
				vis[w.front()]=true;
				w.pop();
			}
		}
//		for(int j=1;j<=n;j++)
//		{
//			cout<<vis[j]<<" ";
//		}
//		cout<<endl;
	}
	cout<<ans;
	cout<<endl;
	return 0;
}
