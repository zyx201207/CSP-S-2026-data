#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
const ll M=5e5+8,N=508,INF=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q,st,ed,entrance[M],temp1,temp2;
struct StationNode
{
	ll id,tm;
};
vector <StationNode> station[M];
ll mp[N][N];
ll read(){
	ll base=0,sign=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') sign=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		base=(base<<3)+(base<<1)+ch-'0';
		ch=getchar();
	}
	return base*sign;
}
ll cal(int s,int t)
{
	ll ans=INF;
	for(int i=0;i<station[s].size();i++)
	{
		for(int j=0;j<station[t].size();j++)
		{
			ans=min(ans,mp[station[s][i].id][station[t][j].id]+station[s][i].tm+station[t][j].tm);
		}
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++) mp[i][j]=INF;
	}
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<=m;i++) entrance[i]=read();
	for(ll i=1,k;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			temp1=read();temp2=read();
			station[temp1].push_back(StationNode{i,temp2});
		}
	}
	//cout<<"Over"<<endl;
	for(int i=1;i<=m;i++)
	{
		if(station[i].size()>=2)
		{
			for(int j=0;j<station[i].size()-1;j++)
			{
				for(int k=j+1;k<station[i].size();k++)
				{
					if(station[i][j].tm+station[i][k].tm<mp[station[i][j].id][station[i][k].id])
					{
						mp[station[i][j].id][station[i][k].id]=station[i][j].tm+station[i][k].tm;
						mp[station[i][k].id][station[i][j].id]=station[i][j].tm+station[i][k].tm;
					}
				}
			}
		}
	}
	//floyd!!!!!!
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(mp[i][k]<INF&&mp[k][j]<INF) mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cout<<mp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	
	while(q--)
	{
		st=read();ed=read();
		cout<<entrance[st]+entrance[ed]+cal(st,ed)<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
