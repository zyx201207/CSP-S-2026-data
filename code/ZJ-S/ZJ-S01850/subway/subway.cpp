#include<bits/stdc++.h>
using namespace std;
long long ans=0,c,d,x,y,q,n,w[500005],k[500005],m,a[505][5005],mm=0,ji,we=0,t[505][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	//for(int i=1;i<=n;i++)
	//{
	//	fa[i]=i;
	//}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][a[i][j]];
			//if(t[i][j]!=t[1][1]) mm=1;
		}
	}
	if(n<=2)
	{
		for(int i=1;i<=q;i++)
		{
			ans=10e9;
			long long qwe=10e9,qi1,qi2,zhong1,zhong2;
			cin>>x>>y;
			long long shu=10e9,a11=0,a22=0,a12=0,a21=0;
			for(int j=1;j<=max(k[1],k[2]);j++)
			{
				if(a[1][j]==x) qi1=t[1][a[1][j]],a11++;
				if(a[1][j]==y) zhong1=t[1][a[1][j]],a12++;
				if(a[2][j]==x) qi2=t[2][a[2][j]],a21++;
				if(a[2][j]==y) zhong2=t[2][a[2][j]],a22++;
			}
			if(a11+a12==2) ans=min(shu,qi1+zhong1);
			if(a21+a22==2) ans=min(shu,qi2+zhong2);
			for(int j=1;j<=k[1];j++)
			{
				for(int qq=1;qq<=k[2];qq++)
				{
				if(a[1][j]==a[2][qq]&&a[1][j]!=0) qwe=min(qwe,t[1][a[1][j]]+t[2][a[2][qq]]);
				}
			}
			if(a11==1&&a22==1) ans=min(ans,qi1+zhong2+qwe);
			if(a12==1&&a21==1) ans=min(ans,qi2+zhong1+qwe);
			ans+=w[x];
			ans+=w[y];
			cout<<ans<<endl;
		}
		return 0;
	}
	if(mm==0)
	{
		
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<endl;
	}
	return 0;
}

