#include<iostream>
#include<cstring>
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;


int n, m;

int a[N];
int cards[M];
int tong[M] = {0};
int vis[N];
int pd[M] = {0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
//	memset(cards, -1, sizeof(cards));
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; ++i)
	{
		
		memset(cards, -1, sizeof(cards));
		memset(vis, 0, sizeof(vis));
		memset(pd, 0, sizeof(pd));
		
		for(int j = i; j <= n; ++j)
		{
			if(cards[a[j]] != -1 && !vis[cards[a[j]]])
			{
				for(int k = cards[a[j]]; k < j; ++k)
				{
					vis[k] = 1;
				}
			}
			cards[a[j]] = j;
		}
		
//		for(int j = 1; j <= m; ++j)
//		{
//			cout << cards[j] << " ";
//		}
//		cout << endl;
		
//		for(int j = i; j <= n; ++j)
//		{
////			vis[j] += vis[j - 1];
//			cout << vis[j] << " ";
//		}
//		cout << endl;
		
		for(int j = i; j <= n; ++j)
		{
			if(!vis[j])
			{
				pd[a[j]] = 1;
			}
		}
		
		for(int j = 1; j <= m; ++j)
		{
			tong[j] += pd[j];
//			cout << pd[j] << " ";
		}
//		cout << endl;
	}
	
	for(int i = 1; i <= m; ++i)
	{
		cout << tong[i] << " "; 
	}
	
	
//	for(int i = 1; i <= n; ++i)
//	{
//		cin >> a[i];
//		if(cards[a[i]] != -1)
//		{
//			for(int j = 1; j <= m; ++j)
//			{
//				if(cards[j] > cards[a[i]])
//				{
//					tong[j] --;
//				}
//			}
//		}
//		cards[a[i]] = i;
//	}
//	
//	for(int i = 1; i <= m; ++i)
//	{
//		tong[i] += cards[i];
//		cout << tong[i] << " ";
//	}
	
	return 0;
}
