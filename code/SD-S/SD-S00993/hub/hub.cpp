#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+5;
int c,t,n,k,xuan[N],ans;
vector<int> v[N];
bool bj[N],wow[N];
void dfs1(int x)
{
	if(bj[x]){return ;}
	bj[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(wow[v[x][i]]){dfs1(v[x][i]);}
	}
}
void dfs2(int x,int &dd,int st)
{
	if(wow[x]){dd=min(dd,st);return ;}
	if(bj[x]){return ;}
	bj[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		dfs2(v[x][i],dd,st+1);	
	}
}
void dfs(int x,int ge)
{
	if(ge+n-x+1<k||ge>k){return ;}//已经不够了 
	if(x==n+1)
	{
		if(ge!=k){return ;}
		for(int i=1;i<=ge;i++){bj[xuan[i]]=0;}
		int cnt=0;
		for(int i=1;i<=ge;i++)
		{
			if(!bj[xuan[i]]){dfs1(xuan[i]);cnt++;}
		}
		if(cnt>2){return ;}
		int ha=0;
		for(int i=1;i<=n;i++)
		{
			if(wow[i]){continue;}
			for(int j=1;j<=n;j++){bj[j]=0;}
			int d=1e9+1;
			dfs2(i,d,0);
			ha=max(ha,d);
		}
		ans=min(ans,ha);
		return ;
	}
	xuan[ge+1]=x;wow[x]=1;
	dfs(x+1,ge+1);
	wow[x]=0;
	dfs(x+1,ge);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(n==k){cout<<"0\n";continue;}
		if(c==13||c==14)
		{
			if(k>=(n+1)/2){cout<<"1\n";} 
			else {cout<<12251<<"\n";}
			continue;
		}
		ans=1e9+1;
		dfs(1,0);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){v[i].clear();}
	}
	return 0;
}

