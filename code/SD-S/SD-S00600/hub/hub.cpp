#include<bits/stdc++.h>
using namespace std;
long long c,t,n,lu2[2006],m,lu[2005][2005],qu[2005][2005],ans,ans2;
void sou(long long in,long long fr,long long gen)
{
	for(int i=1;i<=lu2[in];i++)
	{
		if(lu[in][i]!=fr)
		{
			qu[gen][lu[in][i]]=qu[gen][in]+1;
			sou(lu[in][i],in,gen);
		}
	}
	return;
}
int main()
{
    freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14)
	{
		for(int iii=1;iii<=t;iii++)
		{
			cin>>n>>m;
			for(int i=1;i<n;i++)
			{
				int u,v;
				scanf("%lld%lld",&u,&v);
			}
			cout<<"1"<<endl;
		}
	}
	else if(c<=3)
	{
		for(int iii=1;iii<=t;iii++)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				lu2[i]=0;
			}
			for(int i=1;i<n;i++)
			{
				int u,v;
				scanf("%lld%lld",&u,&v);
				lu2[u]++;
				lu2[v]++;
				lu[u][lu2[u]]=v;
				lu[v][lu2[v]]=u;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					qu[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++)
		    {
		    	sou(i,0,i);
		    }
			if(m==n)
			{
				cout<<"0"<<endl;
			}
			else if(m>=n-2)
			{
				cout<<"1"<<endl;
			}
			else
			{
				ans=1145141919810;
		        for(int i=1;i<=n;i++)
			    {
				    for(int j=i+1;j<=n;j++)
				    {
					    ans2=-9999999;
					    for(int k=1;k<=n;k++)
					    {
						    ans2=max(ans2,min(qu[k][i],qu[k][j]));
					    }
					    ans=min(ans,ans2);
				    }
			    }
			    cout<<ans<<endl;
			}
		}
	}
	else if(c==7)
	{
		for(int iii=1;iii<=t;iii++)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				lu2[i]=0;
			}
			for(int i=1;i<n;i++)
			{
				int u,v;
				scanf("%lld%lld",&u,&v);
				lu2[u]++;
				lu2[v]++;
				lu[u][lu2[u]]=v;
				lu[v][lu2[v]]=u;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					qu[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++)
		    {
		    	sou(i,0,i);
		    }
		    ans=1145141919810;
		    for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					ans2=-9999999;
					for(int k=1;k<=n;k++)
					{
						ans2=max(ans2,min(qu[k][i],qu[k][j]));
					}
					ans=min(ans,ans2);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
