//SN-S00464 王均诚 陕西省西安中学
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int , int> PII;
const int N = 5e5 + 10;
int subways[50][N][2];

ll c , n , m , d , q;
int time1[N];

void dijkstra(int s , int e)
{
	priority_queue<PII , vector<PII> , greater<PII> > heap;

}


int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , " w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1 ; i <= m ; i++) cin >> time1[i];
	
	for (int i = 1 ; i <= n ; i++)
	{
		int k;
		cin >> k;
		for (int j = 0 ; j < k ; j++)
		{
			cin >> subways[i][j][0] >> subways[i][j][1];
		}
		
	}
	
	for (int i= 1 ; i <= q ; i++)
	{
		ll s , e , sum = 0;
		cin >> s >> e;
		sum += time1[s] + time1[e];
		
	}
	return 0;
}
