#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define vector basic_string
using namespace std;

template<typename T1,typename T2>
inline void MIN(T1 &a,T2 b) {a=a<b?a:b;}
template<typename T1,typename T2>
inline void MAX(T1 &a,T2 b) {a=a<b?b:a;}

const int N=4010;

int n,k,C;
vector<int> e[N];

int v[N],d[N];
int fa[N]; 
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}

void dfs(int x,int f,int dd)
{
	MIN(d[x],dd);
	for (int i:e[x]) if (i^f) dfs(i,x,dd+1);
}

int get(int s)
{
	if (__builtin_popcount(s)^k) return n;
	for (int i=1;i<=n;i++) v[i]=(s>>i-1)&1;
	for (int i=1;i<=n;i++) fa[i]=i,d[i]=n;
	for (int i=1;i<=n;i++) for (int j:e[i])
		if (v[i] && v[j]) fa[find(j)]=find(i);
	int cnt=0;
	for (int i=1;i<=n;i++) if (fa[i]==i && v[i]) cnt++;
	if (cnt>2) return n;
	for (int i=1;i<=n;i++) if (v[i]) dfs(i,i,0);
	int ret=0;
	for (int i=1;i<=n;i++) if (!v[i]) MAX(ret,d[i]);
	return ret;
}

void work()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<n;i++)
	{
		int u,v; cin>>u>>v;
		e[u]+=v; e[v]+=u; 
	}
	if (13<=C) 
	{
		cout<<(n+1)/2/k<<"\n";
	} 
	
	int ans=n;
	for (int s=0;s<(1<<n);s++)
		MIN(ans,get(s));
	cout<<ans<<"\n";
	
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t; cin>>C>>t;
	while (t--) work();

	return 0;
}

