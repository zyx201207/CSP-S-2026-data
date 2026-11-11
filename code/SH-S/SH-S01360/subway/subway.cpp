#include<bits/stdc++.h>
using namespace std;
int ceshidian,n,m,d,q;
int w[500005],sa[505],sta[500005];
int s[505][300005];
int main()
{
	freopen("subway.in","r",stdin);//ÊäÈëºÍÊä³ö 
	freopen("subway.out","w",stdout);
	cin>>ceshidian>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>sa[i];
		for(int j=1;j<=sa[i];j++)
		{
			int x;
			cin>>x;
			cin>>s[i][x];
		}
	}
	for(int sum11=1;sum11<=q;sum11++)
	{
		int st,sd;
		cin>>st>>sd;
		int cnt=0;
		cnt+=w[st];
		cnt+=w[sd];
		int minn=1e9,minx;
		for(int i=1;i<=n;i++)
		{
			if(s[i][st]<=minn)
			{
				minn=s[i][st];
				manx=i;
			}
		}
		cnt+=minn;
	}
}
