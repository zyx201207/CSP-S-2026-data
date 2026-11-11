#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],Max,M,b[30];
void dfs(int k,int u,int v)
{
	if(u==m)
	{
		Max=max(Max,v);
		return;
	}
	for(int i=k+1;i<=n;i++) dfs(i,u+1,v&a[i]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),M=max(M,a[i]);
	Max=0;
	if(n<=20)
	{
		for(int i=1;i<=n-m+1;i++) dfs(i,1,a[i]);
		cout<<Max<<endl;
		return 0;
	} 
	else if(m==1)
	{
		for(int i=1;i<=n;i++) Max=max(Max,a[i]);
		cout<<Max<<endl;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		    if(i!=j) Max=max(Max,a[i]&a[j]);
		cout<<Max<<endl;
		return 0;
	}
	else if(M<=4)
	{
		for(int i=1;i<=n;i++) b[a[i]]++;
		if(b[4]>=m) cout<<4<<endl;
		  else if(b[3]>=m) cout<<3<<endl;
		    else if(b[2]+b[3]>=m) cout<<2<<endl;
		      else cout<<1<<endl;
	}
	else if(m==n-1)
	{
		int u=0x3f3f3f3f,op=0;
		for(int i=1;i<=n;i++)
		  if(u>a[i]) u=a[i],op=i;
		int po=0;
		if(op!=1) po=a[1];
		  else po=a[2];
		for(int i=1;i<=n;i++)
		  if(i!=op) po&=a[i];
		cout<<po<<endl;
		return 0;
	}
	return 0;
}
