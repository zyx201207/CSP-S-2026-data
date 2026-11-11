#include<bits/stdc++.h>
using namespace std;
long long xlie[2000010]={};
long long ansl=0;
long long anssh=0;
bool ken=1;
long long d=0;
int lmin=2000010;
void sr(int u,int v,int l)
{
	int nxt=u+1;
	while(nxt<=v&&xlie[nxt]-xlie[u]<=d)
	{
		if(nxt==v)
		{
			if(lmin==l)
			{
				ansl++;
			}
			else
			{
				if(lmin>l)
				{
					lmin=l;
					ansl=1;
				}
			}
			return;
		}
		else
		{
			sr(nxt,v,l+1);
		}
		nxt++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c;int t;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int n=0;
		cin>>n>>d;
		anssh=0;
		for(int j=0;j<n;j++)
		{
			cin>>xlie[j];
		} 
		for(int j=0;j<n;j++)
		{
			for(int r=j+1;r<n;r++)
			{
				lmin=2000010;
				ansl=0;
				sr(j,r,0);
				if(ansl==2)
				{
					anssh++;
					//cout<<j<<" "<<r<<'\n';
				}
			}
		}
		cout<<anssh<<'\n';
		for(int j=0;j<n;j++)
		{
			xlie[j]=0;
		} 
	}
	//记得清空数据 
	return 0;
} 
