#include <bits/stdc++.h>
using namespace std;
int a[500005];
vector<int> line[505];
vector<int> l[505];
vector<int> vis[500005];
struct node{
	int val;
	int ans;
	int lines;
	int before;
};
queue<node> q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int chang;
		cin>>chang;
		for(int j = 1;j<=chang;j++)
		{
			int a1,t;
			cin>>a1>>t;
			line[i].push_back(a1);
			vis[a1].push_back(i);
			l[i].push_back(t);
		}
	}
	for(int i = 1;i<=q;i++)
	{
		int start,end,ans=999999999;
		cin>>start>>end;
		for(int i=1;i<=vis[start].size();i++)
		{
			node o={start,0,vis[start][i],0};
			q.push(o);
		}
		while(!q.empty())
		{	
			node v=q.front();
			q.pop();
			if(v.val==end)
			{
				ans=min(v.ans,ans);
			}
			for(int i=1;i<=vis[v.val].size();i++)
			{
				if(v.lines!=vis[v.val][i])
				{			
					q.push({v.val,v.ans+a[v.val],line[v.val][i],v.val});
				}
			}
			for(int i = 1;i<=line[v.lines].size();i++)
			{
				if(line[v.lines][i]==v.val)
				{
					if(v.before!=line[v.lines][i-1])
					{
						q.push({line[v.lines][i-1],v.ans+l[line[v.lines][i-1]],v.lines,v.val});
					}
					if(v.before!=line[v.lines][i+1])
					{
						q.push({line[v.lines][i+1],v.ans+l[line[v.lines][i+1]],v.lines,v.val});
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}