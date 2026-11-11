#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int c,n,m,d,q;

int mei[505][500005];

int w[500005],k[505];

struct ting
{
	int w;
	bool l[505];
	int t[505];
}b[500005];

int cnt=0;

bool suan(int x,int y)
{
	if(x==y)
	{
		return true;
	}
	int ccnt=1e9;
	for(int i=1;i<=505;i++)
	{
		if(b[x].l[i])
		{
			for(int j=1;j<=k[i];j++)
			{
				if(suan(mei[i][j],y))
				{
					ccnt=min(b[x].t[i],ccnt);
				}
			}
		}
	}
	cnt+=ccnt;
}

int main()
{
	
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			mei[i][j]=x;
			b[x].l[i]=true;
			b[x].t[i]=y;
		} 
	} 
	for(int i=1;i<=q;i++)
	{
		int x,y,ans=0;
		cin>>x>>y;
		ans=ans+w[x]+w[y];
		cnt=0;
		if(suan(x,y))ans+=cnt;
		cout<<ans<<endl;
	}
    return 0;
}

