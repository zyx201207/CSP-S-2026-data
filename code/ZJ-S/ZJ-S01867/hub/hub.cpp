#include<bits/stdc++.h>
using namespace std;
const int inf=1e9,N=1e6+5;
int ans=inf,dist[N],Type,T,n,k,l,r,p,mx;
bool b[N],d[N];
vector<int> a[N];
void FR()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
int in()
{
	char ch=getchar();
	int num=0;
	while(!isdigit(ch))
	  ch=getchar();
	while(isdigit(ch))
	  num=num*10+ch-48,ch=getchar();
	return num;
}
void dfs(int id,bool link)
{
	d[id]=true;
	if(b[id])
	  if(link)
		b[id]=false,dist[id]=0;else
		return;
	for(int i=0;i<a[id].size();++i)
	  if(!d[a[id][i]])
	    dist[a[id][i]]=dist[id]+1,dfs(a[id][i],link&&b[a[id][i]]);
}
int main()
{
	FR();
	Type=in(),T=in();
	while(T--)
	{
		for(int i=1;i<=n;++i)
		  a[i].clear();
		n=in(),k=in();
		for(int i=1;i<n;++i)
		{
			l=in(),r=in();
			a[l].push_back(r);
			a[r].push_back(l);
		}
		if(Type<=3)
		{
			ans=inf;
			for(int i=0;i<(1<<n);++i)
			  if(__builtin_popcount(i)==k)
			  {
				for(int j=1;j<=n;++j)
				  d[j]=false,dist[j]=0;
			  	for(int j=1;j<=n;++j)
			  	  if((i>>j-1)&1)
			  	    b[j]=true;else
			  	    b[j]=false;
			  	p=0;
			  	for(int j=1;j<=n;++j)
			  	  if(b[j])
			  	    dfs(j,1),++p;
			  	if(p>2)
			  	  continue;
			  	mx=0;
			  	for(int j=1;j<=n;++j)
			  	  mx=max(mx,dist[j]);
			  	ans=min(ans,mx);
			  }
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//15 latest
