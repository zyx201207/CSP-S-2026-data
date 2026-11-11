#include <iostream>
#include <queue>
using namespace std;
int n,m,c,d,q;
int w[510];
int a[510][500010];
int t[510][500010];

bool visited[500010];
long long ans = 0;
int T = 0;
queue <int> qu;

void wash()
{
    for(int i=1;i<=m;i++)
    {
        visited[i] = false;
    }
}
int flag_bfs(int x)
{
    int step = 0;
    int pos = x;
}
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	bool flag = true;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> a[i][j] >> t[i][j];
			if(T == 0)
			{
				T = t[i][j];
			}
			else
			{
				flag = flag && (t[i][j] == T);
			}
		}
	}
	while(q--)
    {
        int x,y;
        cin >> x >> y;
        ans = w[x] + w[y];
        if(flag)
        {

        }

        cout << ans << endl;
    }
	return 0;
}
