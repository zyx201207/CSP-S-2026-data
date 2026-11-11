#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define y1 qht_yjx
#define hash ZhaoAk
#define maxn 1005
#define I ios :: sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);
#define rep(i ,l ,r) for (int i = l ;i <= r ;i ++)
#define per(i ,l ,r) for (int i = r ;i >= l ;i --)
#define pb push_back
#define vt vector
#define pii pair <int ,int>


using namespace std;


void chkmxm (int &x ,int y)
{
	x = max (x ,y);
	return ;
}


void chkmnm (int &x ,int y)
{
	x = min (x ,y);
	return ;
}


int n ,k ,u[maxn] ,v[maxn] ,qwq[maxn];


struct BCJ
{
	int fa[maxn];
	
	void init ()
	{
		rep (i ,1 ,n)
			fa[i] = i;
	}
	
	int find (int x)
	{
		return (fa[x] == x) ? x : fa[x] = find (fa[x]);
	}
	
	void merge (int x ,int y)
	{
		int fx = find (x) ,fy = find (y);
		if (fx == fy)
			return ;
		fa[fx] = fy;
		return ;
	}
		
} s;


int dis[maxn];


vt <int> vec[maxn];


void adde (int u ,int v)
{
	vec[u].pb (v);
	vec[v].pb (u);
	return ;
}


void naive ()
{
	cin >> n >> k;
	rep (i ,1 ,n - 1)
		cin >> u[i] >> v[i] ,adde (u[i] ,v[i]);
	
	int ans = 1e16;
	rep (i ,0 ,n)
	{
		qwq[i] = 1;
		rep (j ,i + 1 ,n)
		{
			qwq[j] = 2;
			if (j != k)
				continue ;
			rep (t ,j + 1 ,n)
				qwq[t] = 0;
			do
			{
//				cout << "-----" << endl;
//				rep (i ,1 ,n)
//					cout << qwq[i] << " ";
//				cout << endl;
				
				s.init ();
				rep (a ,1 ,n - 1)
					if (qwq[u[a]] && qwq[u[a]] == qwq[v[a]])
						s.merge (u[a] ,v[a]);
				
//				rep (i ,1 ,n)
//					cout << s.find (i) << " ";
//				cout << endl;
				
				int res = 0;
				rep (a ,1 ,n)
					rep (b ,1 ,n)
						if (qwq[a] && qwq[a] == qwq[b] && s.find (a) != s.find (b))
							res = 1e16;
				
				if (res == 1e16)
					continue ;
				rep (a ,1 ,n)
					dis[a] = 1e16;
				queue <int> q;
				rep (a ,1 ,n)
					if (qwq[a])
						q.push (a) ,dis[a] = 0;
				while (! q.empty ())
				{
					int u = q.front ();
					q.pop ();
					rep (a ,0 ,(int) (vec[u].size ()) - 1)
					{
						int v = vec[u][a];
						if (dis[v] == 1e16)
							dis[v] = dis[u] + 1 ,q.push (v);
					}
				}
				
				rep (a ,1 ,n)
					chkmxm (res ,dis[a]);
				chkmnm (ans ,res);
				
			} while (next_permutation (qwq + 1 ,qwq + n + 1));
		}
	}
	
	cout << ans << endl;
	
	return ;
}


int dst[maxn][maxn];


void BFS (int st)
{
	queue <int> q;
	rep (i ,1 ,n)
		dst[st][i] = 1e16;
	
	dst[st][st] = 0;
	q.push (st);
	
	while (! q.empty ())
	{
		int u = q.front ();
		q.pop ();
		rep (i ,0 ,(int) (vec[u].size ()) - 1)
		{
			int v = vec[u][i];
			if (dst[st][v] == 1e16)
				dst[st][v] = dst[st][u] + 1 ,q.push (v);
		}
	}
	
	return ;
}


void solveld ()
{
	cin >> n >> k;
	rep (i ,1 ,n - 1)
		cin >> u[i] >> v[i] ,adde (u[i] ,v[i]);
	int ans = 1e16;
	rep (i ,1 ,n)
		rep (j ,i + 1 ,n)
		{
			int res = 0;
			rep (k ,1 ,n)
			{
				chkmxm (res ,min (dst[i][k] ,dst[j][k]));
				if (res > ans)
					break ; 
			}
			chkmnm (ans ,res);
		}
	
	cout << ans << endl;
	
	return ;
}


signed main ()
{
	I AK CSP
	
	freopen ("hub.in" ,"r" ,stdin);
	freopen ("hub.out" ,"w" ,stdout);
	
	int c ,T;
	cin >> c >> T;
	
	while (T --)
	{
		if (c == 7)
			solveld ();
		else
			naive ();
	}

	return !!!!! ("ShZhao" && "SHzhao");
}

/*
0 1
5 2
1 2
2 3
3 4
4 5
*/