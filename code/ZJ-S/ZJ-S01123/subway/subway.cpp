#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,b,x,y,cdd[500500],mi[500500],dtzdc[505];
struct ee
{
	int zd,sc;
}dd,ff,gg;
queue <ee> fg; 
vector <ee> dtzd[505],zddt[500500];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>cdd[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		for(int j=1;j<=b;j++) {cin>>x>>y; dd.sc=y; dd.zd=x; dtzd[i].push_back(dd); dd.sc=y; dd.zd=i; zddt[i].push_back(dd); dtzdc[i]++;}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=m;j++) mi[j]=INT_MAX;
		mi[x]=0;
		dd.sc=0;dd.zd=x;
		fg.push(dd);
		while(!fg.empty())
		{
			dd=fg.front();
			fg.pop();
			for(int k=0;k<zddt[dd.zd].size();k++)
			{
				int kk=zddt[dd.zd][k].zd;
				for(int l=0;l<dtzd[kk].size();l++)
				{
					if(dd.sc+dtzd[kk][l].sc<mi[dtzd[kk][l].zd])
					{
						mi[dtzd[kk][l].zd]=dd.sc+dtzd[kk][l].sc;
						ff.sc=dd.sc+dtzd[zddt[dd.zd][k].zd][l].sc;
						ff.zd=dtzd[kk][l].zd;
						fg.push(ff);
					}
				}
			}
		}
		cout<<mi[y]<<"\n";
	}
	
	return 0;
}
