#include<bits/stdc++.h>
using namespace std;
int ckck,n,m,t,k,x,y;
int f[2000010];
int cz(int x)
{
	return f[x]==x?x:f[x]=cz(f[x]);
}
void hb(int x,int y)
{
	int fx=cz(x);
	int fy=cz(y);
	if(fx!=fy)
	{
		f[fx]=fy;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ckck>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
		}
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			hb(x,y);
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==i)
			{
				sum++;
			}
		}
		cout<<k-sum<<endl;
	}
	return 0;
}
