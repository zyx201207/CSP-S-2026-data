#include<bits/stdc++.h>
using namespace std;
int n,m,a[200007],ans,nid,id;
vector<int>w[40];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int t = a[i],cnt = 0;
		while(t != 0)
		{
			if(t%2==1)w[cnt].push_back(i);
			t /= 2;
			cnt++;
		}
	}
	for(int i = 30;i >= 0;i--)
	{
		if(w[i].size() >= m)
		{
			ans += (1<<i);
			id = i;
			break;
		}
	}
	while(id != -1)
	{
		nid = -1;
		for(int i = 0;i <= 30;i++)
		{
			if(i == id)break;
			w[i].clear();
		}
		for(int i = 0;i < w[id].size();i++)
		{
			int t = a[w[id][i]],cnt = 0;
			while(t != 0&&cnt < id)
			{
				if(t%2==1)w[cnt].push_back(w[id][i]);
				t /= 2;
				cnt++;
			}
		}
		for(int i = id-1;i >= 0;i--)
		{
			if(w[i].size() >= m)
			{
				ans += (1<<i);
				nid = i;
				break;
			}
		}
		id = nid;
		
	}
	cout << ans << endl;
	return 0;
}
