#include <bits/stdc++.h>
using namespace std;
#define int long long
int w1[505];
vector<int> vt[505];
int a[500005],t[500005];
int v[5005][5005];
bool b[500005];
int x,y;
int ans=0;
void dfs(int p,int cnt)
{
	if(p==y)
	{
		ans=max(ans,cnt);
		return;
	}
	b[p]=1;
	for(int i=0;i<vt[p].size();i++)
	{
		if(b[vt[p][i]]==0)
		{
			dfs(vt[p][i],cnt+v[p][vt[p][i]]);
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w1[i];
		//cout << w1[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> a[j]>>t[j];
		}
		for(int j=2;j<=k;j++)
		{
			vt[a[j-1]].push_back(a[j]);
			vt[a[j]].push_back(a[j-1]);
			v[a[j-1]][a[j]]=t[j]+t[j-1];
			v[a[j]][a[j-1]]=t[j]+t[j-1];
		}
	
	}
	//for(int i=1;i<=m;i++) cout << w1[i]<<" ";
	while(q--)
	{
		cin >> x >> y;
		memset(b,0,sizeof(b));
		ans=0;
		dfs(x,0);	
		//cout << ans<<" "<<w1[x]<<" "<<w1[y]<<" ";
		ans+=w1[x]+w1[y];
		cout << ans<<endl;
	}
	return 0;
}
