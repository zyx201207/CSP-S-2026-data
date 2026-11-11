#include<bits/stdc++.h>
using ll=long long;
using namespace std;

const int maxn=1e6+10;

int n,k;
int fa[maxn],bel[maxn],sizee[maxn];

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)fa[i]=i,bel[i]=i,sizee[i]=1;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			if(find(u)==find(v))continue;
			ll fx=find(u),fy=find(v);
			fa[find(u)]=find(v);
//			sizee[find(v)]+=sizee[find(u)];
		}
		for(int i=1;i<=n;i++)sizee[find(i)]+=sizee[i];
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,sizee[i]/2);
//			cout<<sizee[i]<<endl;
		}
		cout<<maxx/4+(maxx%4==0)<<endl;
	}
	return 0;
}
//he tong xue bei kao bei,huan jie le yi xie ya li
// dan ya li hai shi heng da,T1 bie gua jiu hao
//ruo xin wu gui chu,ti hai bian shi gui su!!!
// jia you wo de tong xue meng ,zhu ni men jin noip!
// zzx jia you ni hui ying de, dui ba (xiao) 
