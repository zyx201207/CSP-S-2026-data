#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,c[100],gs,mx,answei,mi[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
int zt[1048580][20];
bool f,tt=1;
struct qjj{
	int a,b[40],wei;
}str[200005];
bool cmp(qjj l,qjj r)
{
	return l.a>r.a;
}
void dfs(int xy,int yq,int ycs,string sss)
{
	if(yq+xy-ycs<m) return;
	if(ycs==xy)
	{
		if(yq!=m) return;
		++gs;
		for(int i=0;i<xy;i++)
			zt[gs][i]=sss[i]-'0';
		return;
	}	
	dfs(xy,yq,ycs+1,sss+'0');
	dfs(xy,yq+1,ycs+1,sss+'1');

}
void daorong(int x,int id)
{
	int ss=0;
	while(x)
	{
		str[id].b[ss++]=x%2;
		x/=2;
	}
	str[id].wei=ss-1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<30;i++)
		if(n==mi[i]) tt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i].a;
		daorong(str[i].a,i);
	}
	if(n<=20)
	{
		dfs(n,0,0,"");
		for(int i=1;i<=gs;i++)
		{
			ans=0;answei=0;
			memset(c,0,sizeof(c));f=0;
			for(int j=0;j<n;j++)
			{
				//cout<<zt[i][j]<<' ';
				if(zt[i][j]==1)
				{
					if(f==0)
					{
						for(int k=0;k<=str[j+1].wei;k++)
							c[k]=str[j+1].b[k];
						answei=str[j+1].wei;
						f=1;
					}	
					else
					{
						
						for(int k=0;k<=max(str[j+1].wei,answei);k++)
							if(str[j+1].b[k]==1&&c[k]==1)
								c[k]=1;
							else c[k]=0;
						answei=max(answei,str[j+1].wei);
					}
				}
			}
			for(int i=0;i<=answei;i++)
				ans+=c[i]*mi[i];
			mx=max(mx,ans);
		}
		cout<<mx;
		return 0;	
	}
	if(m==1)
	{
		sort(str+1,str+1+n,cmp);
		cout<<str[1].a;
		return 0;
	}
	if(m==n)
	{
		for(int j=0;j<n;j++)
			{
					if(f==0)
					{
						for(int k=0;k<=str[j+1].wei;k++)
							c[k]=str[j+1].b[k];
						answei=str[j+1].wei;
						f=1;
					}	
					else
					{
						
						for(int k=0;k<=max(str[j+1].wei,answei);k++)
							if(str[j+1].b[k]==1&&c[k]==1)
								c[k]=1;
							else c[k]=0;
						answei=max(answei,str[j+1].wei);
					}
			}
			for(int i=0;i<=answei;i++)
				ans+=c[i]*mi[i];
			cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				
				if(i==j) continue;
				ans=0;answei=0;
				memset(c,0,sizeof(c));
				for(int k=0;k<=str[i].wei;k++)
					c[k]=str[i].b[k];
				answei=str[i].wei;	
				for(int k=0;k<=max(str[j].wei,answei);k++)
					if(str[j].b[k]==1&&c[k]==1)
						c[k]=1;
					else c[k]=0;
				for(int k=0;k<=answei;k++)
					ans+=c[k]*mi[k];
				mx=max(mx,ans);
			}
		}
		cout<<mx;
		return 0;
	}
	if(tt==0) 
	{
		cout<<n-m;
		return 0;
	}
	else
	{
		sort(str+1,str+1+n,cmp);
		for(int i=1;i<=m;i++)
		if(i==1)
		{
			for(int j=0;j<=str[i].wei;j++)
				c[j]=str[i].b[j];	
		}
		else 
		{
//			for(int j=0;j<=str[i].wei+1;j++)
//				cout<<str[i].b[j];
			for(int j=0;j<=max(str[i].wei,answei);j++)
				if(str[i].b[j]==1&&c[j]==1)
					c[j]=1;
				else c[j]=0;
			answei=max(answei,str[i].wei);
			
//			cout<<'\n';
		}
		for(int i=0;i<=answei;i++)
			ans+=c[i]*mi[i];
		cout<<ans;
		return 0;
	}
}
/*
4 2
3 15 12 12
*/