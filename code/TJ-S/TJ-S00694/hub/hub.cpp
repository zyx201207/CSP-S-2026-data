#include <cstdio>
#include <vector>

const int N = 1e6+5;
int c, t, n, k;
std:vector<int> e[N];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while(t --)
	{
		scanf("%d%d", &n, &k);
		for(int i=1; i<n; i++)
		{
			int ui, vi;
			scanf("%d%d", &ui, &vi);
			e[ui].push_back(vi);
			e[vi].push_back(ui);
		}
	}
	
	
	return 0;
}
