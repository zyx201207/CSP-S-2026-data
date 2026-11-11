#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define y1 qht_yjx
#define hash ZhaoAk
#define maxn 550005
#define I ios :: sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);
#define rep(i ,l ,r) for (int i = l ;i <= r ;i ++)
#define per(i ,l ,r) for (int i = r ;i >= l ;i --)
#define pb push_back
#define vt vector
#define pii pair <int ,int>


using namespace std;


void chkmnm (int &x ,int y)
{
	x = min (x ,y);
	return ;
}


int c ,n ,m ,d ,q ,dis[505][505] ,tmp[maxn] ,vis[maxn] ,w[maxn];


struct node
{
	int v ,w;
	
	friend bool operator < (node a ,node b)
	{
		return a.w > b.w;
	}
	
} ;


vt <node> vec[maxn];


//void adde (int u ,int v ,int w)
//{
//	vec[u].pb ({v ,w});
//	vec[v].pb ({u ,w});
//	return ;
//}


//void Dijkstra (int st)
//{
//	rep (i ,1 ,n + m)
//		tmp[i] = 1e16 ,vis[i] = 0;
//	tmp[st + m] = 0;
//	
//	priority_queue <node> q;
//	q.push ({st + m ,0});
//	
//	while (! q.empty ())
//	{
//		node zc = q.top ();
//		q.pop ();
//		int u = zc.v;
//		if (vis[u])
//			continue ;
//		vis[u] = 1;
//		rep (i ,0 ,(int) (vec[u].size ()) - 1)
//		{
//			int v = vec[u][i].v ,w = vec[u][i].w;
//			if (tmp[u] + w < tmp[v])
//			{
//				tmp[v] = tmp[u] + w;
//				q.push ({v ,tmp[v]});
//			}
//		}
//	}
//	
//	rep (i ,1 ,n)
//		dis[st][i] = tmp[i + m];
//	
//	return ;
//}


signed main ()
{
	I AK CSP
	
	freopen ("subway.in" ,"r" ,stdin);
	freopen ("subway.out" ,"w" ,stdout);
	
	cin >> c >> n >> m >> d >> q;
	rep (i ,1 ,m)
		cin >> w[i];
	rep (i ,1 ,n)
	{
		int k;
		cin >> k;
		rep (j ,1 ,k)
		{
			int x ,t;
			cin >> x >> t;
//			adde (x ,i + m ,t); // 1 至 m 为实点，m + 1 至 m + n 为虚点。
			vec[x].pb ({i ,t});
		}
	}
	
	rep (i ,1 ,n)
		rep (j ,1 ,n)
			dis[i][j] = 1e16;
	rep (i ,1 ,n)
		dis[i][i] = 0;
	
	rep (i ,1 ,m)
	{
//		cout << "---" << i << "---" << endl;
		rep (j ,0 ,(int) (vec[i].size ()) - 1)
			rep (k ,0 ,(int) (vec[i].size ()) - 1)
			{
				int v1 = vec[i][j].v ,w1 = vec[i][j].w ,v2 = vec[i][k].v ,w2 = vec[i][k].w;
//				cout << v1 << " " << v2 << endl;
				chkmnm (dis[v1][v2] ,w1 + w2);
				chkmnm (dis[v2][v1] ,w2 + w1);
			}
	}
	
	rep (k ,1 ,n)
		rep (i ,1 ,n)
			rep (j ,1 ,n)
				chkmnm (dis[i][j] ,dis[i][k] + dis[k][j]);
	
//	rep (i ,1 ,n)
//		Dijkstra (i);
		
//	rep (i ,1 ,n)
//	{
//		rep (j ,1 ,n)
//			cout << dis[i][j] << " ";
//		cout << endl;
//	}
		
	while (q --)
	{
		int x ,y;
		cin >> x >> y;
		int ans = 1e16;
		rep (i ,0 ,(int) (vec[x].size ()) - 1)
		{
			int v = vec[x][i].v ,w = vec[x][i].w;
			rep (j ,0 ,(int) (vec[y].size ()) - 1)
			{
				int v_ = vec[y][j].v ,w_ = vec[y][j].w;
				chkmnm (ans ,dis[v][v_] + w_ + w);
//				cout << v - m << " " << v_ - m << " " << w_ << " " << w << endl;
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}

	return !!!!! ("ShZhao" && "SHzhao");
}

// 沉石之鱼尚能惊旋，不鸣之鸟亦能一鸣惊人。
// 经过卡卡时卡卡空过后的最终版。 