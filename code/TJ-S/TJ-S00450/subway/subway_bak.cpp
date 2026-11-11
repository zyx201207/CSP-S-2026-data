#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int> > conn[500005], tmpp[500005];

int fa[500005][20], tmp[500005][20];
void dfs(int x, int f)
{
	fa[x][0] = f;
	for(int i = 1; i <= 19; i++)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(auto i : conn[x])
		if(i.first.first != fa)
			tmp[i.first.first][0] = i.second, dfs(i, x);
}

void dfs2(int x, int fa, vector<int>& tmp, int pre)
{
	int posp = -1;
	for(auto i : tmpp[x])
	{
		bool have = tmp.find(i.first.second) != tmp.end();
		if(i.first.second != pre && have)
			continue;
		conn[x].push_back(i);
		if(!have) tmp.push_back(i.first.second);
		dfs2(i.first.first, x, tmp, i.first.second);
		tmp.pop_back();
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	return 0;
}

