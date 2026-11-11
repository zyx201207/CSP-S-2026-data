#include<bits/stdc++.h>
using namespace std;
const int M=500010;
const int N=550;
int c,n,m,d,q;
int ll,rr;
struct nod{
	int t,a;
}p[N];
struct subw{
	int l,r,t[5];
}kmpp[N];
int k[N];
int maxx=-1;
int w[M];
long long ans;
int cmp1(subw x,subw y)
{
	if(x.l==y.l) return x.t[1]+w[x.l]<y.t[1]+w[y.l];
	return x.l<y.l;
}
void run1(int lo,long long time)
{
	
}
void run2(int lo,long long time,int dt)
{
	if(lo==rr)
	{
		ans=min(ans,time+kmpp[dt].t[2]+w[lo]);
		return ;
	}
	int locc=dt+1;
	for(int i=locc;i<=n;i++)
	{
		if(k[i]==1) continue;
		if(kmpp[i].l==lo)
		{
			run2(kmpp[i].r,time+kmpp[dt].t[2]+kmpp[i].t[1],i);
			break;
		}
	}
}
void run()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		maxx=max(maxx,k[i]);
		if(maxx<=2)
		{
			if(k[i]==1) cin>>kmpp[i].l>>kmpp[i].t[1];
			else{
				cin>>kmpp[i].l>>kmpp[i].t[1];
				cin>>kmpp[i].r>>kmpp[i].t[2];
			}
			continue;
		}else{
			for(int j=1;j<=k[i];j++)
			{
				cin>>p[j].a>>p[j].t;
			}	
		}
	}
	if(maxx<=2)
	{
		sort(kmpp+1,kmpp+1+n,cmp1);
		for(int i=1;i<=q;i++)
		{
			ans=10000000000000007;
			cin>>ll>>rr;
			int lll=ll,rrr=rr;
			ll=min(lll,rrr);
			rr=max(lll,rrr);
			int loc=0;
			for(int j=1;j<=n;j++)
			{
				if(k[j]==1) continue;
				if(kmpp[j].l==ll)
				{
					loc=j;
					break;
				}
			}
			run2(kmpp[loc].r,w[ll]+kmpp[loc].t[1],loc);
			cout<<ans<<"\n";
		}
		return ;
	}else{
		for(int i=1;i<=q;i++)
		{
			ans=1000000007;
			cin>>ll>>rr;
			run1(ll,0);
			cout<<ans<<"\n";
		}
		return ;
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	run();
	return 0;
}