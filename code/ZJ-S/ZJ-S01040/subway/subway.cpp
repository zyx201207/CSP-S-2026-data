#include<bits/stdc++.h>
using namespace std;
struct site
{
	int tmw;
	int lcnt;
	int llist[25];
	bool vised;
}ss[500005];
struct line
{
	int scnt;
	int slist[505];
	int tl[500005];
	bool vised;
}ls[505];
long long solve(int ed,vector<int> vislist,vector<int> usedtime)
{
	vector<int> nlist;
	vector<int> ntime;
	long long ans=-1;
	for(int i=0;i<vislist.size();i++)
	{
		ss[vislist[i]].vised=true;
		for(int j=1;j<=ss[vislist[i]].lcnt;j++)
		{
			if(!ls[ss[vislist[i]].llist[j]].vised)
			{
				ls[ss[vislist[i]].llist[j]].vised=true;
				line tmp=ls[ss[vislist[i]].llist[j]];
				for(int k=1;k<=tmp.scnt;k++)
				{
					if(!ss[tmp.slist[k]].vised&&ss[tmp.slist[k]].lcnt>1)
					{
						nlist.push_back(tmp.slist[k]);
						ntime.push_back(usedtime[i]+tmp.tl[vislist[i]]+tmp.tl[k]);
					}
					if(tmp.slist[k]==ed)
					{
						long long tp=usedtime[i]+tmp.tl[vislist[i]]+tmp.tl[k]+ss[ed].tmw;
						if(ans=-1)
						{
							ans=tp;
						}
						else if(ans>tp)
						{
							ans=tp;
						}
					}
				}
				ls[ss[vislist[i]].llist[j]].vised=false;
			}
		}
		ss[vislist[i]].vised=false;
	}
	if(nlist.size()==0||ntime.size()==0)
	{
		if(ans!=-1)
		{
			return ans;
		}
		else
		{
			return 2^60;
		}
	}
	
	if(ans==-1)
	{
		ans=solve(ed,nlist,ntime);
	}
	else
	{
		ans=min(ans,solve(ed,nlist,ntime));
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int m,q;
	short c,n,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>ss[i].tmw;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>ls[i].scnt;
		for(int j=1;j<=ls[i].scnt;j++)
		{
			cin>>ls[i].slist[j];
			cin>>ls[i].tl[ls[i].slist[j]];
			ss[ls[i].slist[j]].lcnt++;
			ss[ls[i].slist[j]].llist[ss[ls[i].slist[j]].lcnt]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int st,ed;
		cin>>st>>ed;
		vector<int> tmp1;
		tmp1.push_back(st);
		vector<int> tmp2;
		tmp2.push_back(ss[st].tmw);
		cout<<solve(ed,tmp1,tmp2)<<endl;
	}
	return 0;
}
