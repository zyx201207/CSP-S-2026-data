 #include<bits/stdc++.h>
 #define int long long
 #define pairr pair<long long,long long>
 using namespace std;
 int c,n,m,d,q;
 struct nmd
 {
 	int a,w;	
 };
 vector<nmd> mtn[500010];
 int ntn[555][555];
 int mto[500010];
 vector<pairr> ntu[555];
 priority_queue<pairr ,vector<pairr> ,greater<pairr> > que;
 bool f[555];
 signed main()
 {
 	std::ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	memset(ntn,0x3f,sizeof(ntn));
 	cin>>c>>n>>m>>d>>q;
 	for(int i=1;i<=n;i++)
 	{
		ntn[i][i]=0;	
	}
 	for(int i=1;i<=m;i++)
 	{
 		cin>>mto[i];
	}
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		while(num--)
		{
			int a,w;
			cin>>a>>w;
			for(auto v:mtn[a])
			{
				ntu[i].push_back({w+v.w,v.a});
				ntu[v.a].push_back({w+v.w,i});
			}
			mtn[a].push_back({i,w});
		}
	}
	for(int s=1;s<=n;s++)
	{
		que.push({0,s});
		memset(f,0,sizeof(f));
		while(!que.empty())
		{
			int u=que.top().second,w=que.top().first;
			que.pop();
			if(f[u]) continue;
			f[u]=1;
			ntn[s][u]=w;
			for(auto pv:ntu[u])
			{
				int v=pv.second,ww=pv.first;
				if(ntn[s][v]>ww+w)
				{
					que.push({ww+w,v});
				}
			}
		}
	}
	while(q--)
	{
		int u,v,ans=0x3FFFFFFFFFFFFFFF;
		cin>>u>>v;
		if(u==v)
		{
			cout<<0<<'\n';
			continue;
		}
		for(auto i:mtn[u])
		{
			for(auto j:mtn[v])
			{
				ans=min(ans,i.w+j.w+ntn[i.a][j.a]);
			}
		}
		cout<<mto[u]+mto[v]+ans<<'\n';
	}
	return 0;
 }
