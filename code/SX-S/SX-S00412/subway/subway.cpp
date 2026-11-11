#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N],vvs[N],ss[N];
vector<int> a[510],t[510],vis[N];
map<int,int> ma[510];
long long c,n,m,d,q1,k,a1,t1,xx,y,ans;
void bfs(int x)
{
	int b,b1,s1=0,l,f;
	//string s,s2;
	queue<int> q,bq;
	//queue<string> sq;
	q.push(x);
	bq.push(w[x]);
	//sq.push("0");
	vvs[x]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		b=bq.front();
		bq.pop();
		/*s=sq.front();
		sq.pop();
		l=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!=' ')
				s1=s1*10+(s[i]-'0');
			else
			{
				ss[++l]=s1;
				s1=0;
			}
		}*/
		if(x==y)
		{
			ans=min(ans,1ll*(b+w[y]));
			return;
		}
		for(int i=0;i<vis[x].size();i++)
		{
			/*f=0;
			for(int kk=1;kk<=l;kk++)
			{
				if(ss[kk]==vis[x][i])
				{
					f=1;
					break;
				}
			}
			if(f)
				continue;*/
			for(int j=0;j<a[vis[x][i]].size();j++)
			{
				if(x!=a[vis[x][i]][j])
				{
					q.push(a[vis[x][i]][j]);
					b1=b+t[vis[x][i]][ma[vis[x][i]][x]-1]+t[vis[x][i]][j];
					bq.push(b1);
					vvs[vis[x][i]]=1;
					//s2=s+' '+char(vis[x][i]);
					//sq.push(s2);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
			vis[a1].push_back(i);
			ma[i][a1]=j;
		}
	}
	while(q1--)
	{
		ans=LLONG_MAX;
		memset(vvs,0,sizeof(vvs));
		cin>>xx>>y;
		bfs(xx);
		cout<<ans<<'\n';
	}
	return 0;
}