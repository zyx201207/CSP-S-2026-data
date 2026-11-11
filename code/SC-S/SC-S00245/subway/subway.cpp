#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define debug(x) cerr << "行:" <<  __LINE__ << " 名:" << #x <<':' << x << '\n'; 
using namespace std;
using P = pair<int,long long>;
long long ldp[1010][1010];
void f(int m,vector<long long> &w,vector<vector<int> > &in,vector<vector<P> > &line,vector<vector<long long> > &lon)
{
	int s,t;
	cin >> s >> t;
	vector<long long> dp(m+1);
	vector<bool> vis(m+1);
	priority_queue<P,vector<P>,greater<P>> qu;
	qu.push({s,dp[s] = w[s]});
	vis[s] = 1;
	//debug("hh")
	if(s <= 1000 && t <= 1000 && ldp[s][t] != 0) {cout << ldp[s][t]+w[s]+w[t] << '\n';return;};
	//debug("hh")
	while(qu.size())
	{
		auto[p,l] = qu.top();
		qu.pop();
		for(int j = 0;j < in[p].size();j++)
		{
			int i = in[p][j];
			for(auto[node,len]:line[i])
			{
				if(!vis[node])
				{
					vis[node] = 1;
					if(p <= 1000 && node <= 1000 && ldp[p][node] == 0) ldp[p][node] = len+lon[p][j];
					qu.push({node,dp[node] = len+l+lon[p][j]});
				}
			}
		}
		
	}
	//debug(dp[t])debug(w[t])
	cout << dp[t] + w[t] << '\n';
	//debug(dp[t])debug(w[t])
}
int main()
{
	fre("subway");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int count___,   n,     m,   maxhave___,q;
//     测试点编号   线路数 站数 最多       计划数
	cin >> count___ >> n >> m >> maxhave___ >> q;
	vector<long long> w(m+1);
	vector<vector<int> > in(m+1,vector<int>());
	vector<vector<long long>> lon(m+1,vector<long long>());
	vector<vector<P> > line(n+1,vector<P>());
	
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	//debug("hh")
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		int ai,ti;
		for(int j = 1;j <= k;j++)
		{
			cin >> ai >> ti;
			line[i].push_back({ai,ti});
			in[ai].push_back(i);
			lon[ai].push_back(ti);
		}
	}
	//debug("hh")
	while(q--)
	{
		f(m,w,in,line,lon);
	}
	return 0;
}