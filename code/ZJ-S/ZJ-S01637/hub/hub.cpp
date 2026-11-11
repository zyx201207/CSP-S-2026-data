#include <iostream>
#include <vector>
#define int long long
using namespace std;

int c, t;
int n, k;
vector <int> Tree[1000];

//int answer = -1;
int slist[1000];
int vis[1000];
int dis[1000];
int final_answer = 1 << 30;

int spread(int q, int value)
{
	for (int i = 0; i < Tree[q].size(); i++)
	{
		if (vis[Tree[q][i]] == 0 && slist[Tree[q][i]])
		{
			vis[Tree[q][i]] = value;
			spread(Tree[q][i], value);
		}
	}
	return 0;
}

int check()
{
	for (int i = 0; i < n; i++)
	{
		vis[i] = 0;
	}
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (slist[i] == true && vis[i] == 0)
		{
			spread(i, cnt);
			cnt++;
		}
	}
	if (cnt > 3)
	{
		return false;
	}
	return true;
	//cout << cnt << endl;
	//return true;
}

int spread_dis(int nowat, int dis_step)
{
	//cout << "DIS" << dis_step << endl;
	dis[nowat] = dis_step;
	for (int i = 0; i < Tree[nowat].size(); i++)
	{
		//cout << "TRY" << Tree[nowat][i] << " "<< dis[Tree[nowat][i]] << " "<< endl;
		if (dis[Tree[nowat][i]] > dis_step + 1)
		{
			//cout << "Succeed!" << endl;
			spread_dis(Tree[nowat][i], dis_step + 1);
		}
	}
	return 0;
}

int bfs_get()
{
	for (int i = 0; i < n; i++)
	{
		dis[i] = 1 << 31 - 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (slist[i] == 1)
		{
			spread_dis(i, 0);
		}
	}
	int dis_ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (dis[i] > dis_ans)
			dis_ans = dis[i];
		//cout << dis[i] << " ";
	}
	//cout << endl;
	return dis_ans;
}


int dfs(int lastat, int nowhave)
{
	
	if (nowhave == k)
	{
//		cout << "UNCHECKED" << endl;
//			for (int i = 0; i < n; i++)
//			{
//				if (slist[i] == 1)
//				{
//					cout << i << " ";
//				}
//	
//			}
//				cout << endl;
		if (check())
		{
//			cout << "CHECKDE" << endl;
//			for (int i = 0; i < n; i++)
//			{
//				if (slist[i] == 1)
//				{
//					cout << i + 1<< " ";
//				}
//				//cout << endl;
//			}
//			cout << endl;
			int ppp = bfs_get();
		//	cout << ppp << endl;
			if (ppp < final_answer)
			{
				final_answer = ppp;
				//cout << "FINAL" << final_answer << endl;
			} 
//			cout << endl;
//			cout << endl;
//			cout << endl;
		}
		return 0;
	}
	for (int i = lastat + 1; i < n; i++)
	{
		slist[i] = true;
		dfs(i, nowhave + 1);
		slist[i] = false;
	}
	return 0;	
}

int once()
{
	final_answer = 1 << 30;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		
		Tree[x].push_back(y);
		Tree[y].push_back(x);
	}
	
	dfs(-1, 0);
	cout << final_answer << endl;
	
	return 0;
}


signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		once();
		//return 0;
		//cout << "===" << endl;
	}
	return 0;
}