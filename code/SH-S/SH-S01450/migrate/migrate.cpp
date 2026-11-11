#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,cnt,tt,ss;
long long x[2000005];
long long f[5005][5005];
//long long vis[2000005];
stack<int> s;
void dfs(int p,int q)
{
	if(p==q)
	{	
		if(tt<ans)
			ans=tt,cnt=1;	
		if(tt==ans)
			cnt++;	
		//cout<<tt<<" "<<cnt<<" "<<ans<<endl;
		return;		
	}
	//vis[p]=1;	
	for(int i=p+1;i<=q;i++)
	{
		if(f[p][i]!=0)
		{
			s.push(i);
		}		
	}
	while(!s.empty())
	{
		int u=s.top();
		s.pop();	
		tt++;
		dfs(u,q);
		//vis[u]=0;
		tt--;
	}
}
int main()
{
 	freopen("migrate4.in","r",stdin);
 	//freopen("migrate.out","w",stdout);
 	cin>>c>>t;
 	while(t--)
 	{
 		cin>>n>>d;
 		for(int i=1;i<=n;i++)
 			cin>>x[i];
 		if(n<=5000)
 		{
 			ss=0;
 			for(int i=1;i<=n;i++)
 			{
 				for(int j=i;j<=n;j++)
 					if(x[j]-x[i]<=d)
 						f[i][j]=x[j]-x[i];
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+3;j<=n;j++)
				{
					ans=1e9,cnt=0,tt=0;
					/*for(int k=1;k<=n;k++)
						vis[k]=0;*/
					dfs(i,j);
					//cout<<i<<" "<<j<<" "<<ans<<" "<<cnt<<endl;
					if(cnt==2)
						ss++;
				}
			}
			cout<<ss<<endl;
		}
		else
		{
			ss=0;
			int dd=x[2]-x[1];
			if(2*dd>d)
				ss=0;
			else
			{
				int y=(x[n]-x[1])/d;
				ss=n*(n-1)/2-(n-1)-(n-2)-y*(y-1)/2;
			}	
			cout<<ss<<endl;
		} 		
	}
 	return 0;
}
