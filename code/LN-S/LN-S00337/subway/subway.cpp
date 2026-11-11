#include <bits/stdc++.h>
using namespace std;
const int N=505,K=5e5+5;
//地铁口=>站厅=>站台
//         0    1
int x,y,w[N];//地铁口<=>站厅
struct node
{
	int a;//站台编号
	int t;//站厅<=>站台
};
vector<node>line[N];
vector<int>st_in_line[N];
int work(int now,int l,int ans,bool pos)
{
	if(now==y)
	{
		if(pos==1)
		{
			for(auto x:line[l])
				if(x.a==now)
					return ans+x.t;
		}
		else
			return ans;
	}
	if(pos==0)
	{
		for(auto st:line[l])
			if(st.a==now)
				return work(now,l,ans+st.t,1);
	}
	for(auto st:line[l])
	{
		int na=st.a,nt=st.t;
		if(na==now)
			continue;
		if(st_in_line[na].size()>1)
		{
			for(int new_line:st_in_line[na])
				if(l!=new_line)
					return work(na,new_line,ans+nt,0);
		}
		else
			return work(na,l,ans,1);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int a,t;
			cin>>a>>t;
			line[i].push_back({a,t});
			st_in_line[a].push_back(i);
		}
	}
	while(q--)
	{
		cin>>x>>y;
		int ans=0x3f3f3f3f;
		for(int l:st_in_line[x])
		{
			int sum=work(x,l,w[x],0);
			ans=min(ans,sum);
		}
		ans+=w[y];
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
