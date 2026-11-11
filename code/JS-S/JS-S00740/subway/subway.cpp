//long long
//subway line -> point
//from one line to another at a station -> edge
//add the time of from and to, each with two
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 505;
const int MAXM = 5e5 + 100;
const int MAXD = 25;
const long long INF = 1e18;

long long res = INF;
long long dis[MAXN][MAXN] = {};
long long w[MAXN] = {};
long long a[MAXN] = {},t[MAXN] = {};
int station[MAXM][MAXD] = {};
long long station_time[MAXM][MAXD] = {};
int cnt_line[MAXM] = {};

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	//cout << "~~~~~~~~~~" << endl;

    int c = 0,n = 0, m = 0, d = 0, p = 0;
    cin >> c >> n >> m >> d >> p;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int k = 0;
        cin >> k;
        for(int j = 1;j <= k;j ++)
        {
            cin >> a[j] >> t[j];
            cnt_line[a[j]]++;
            station[a[j]][cnt_line[a[j]]] = i;
            station_time[a[j]][cnt_line[a[j]]] = t[j];
            //cout << cnt_line[a[j]] << endl;
        }
        /*
        for(int s = 1;s <= k;s++)
        {
            for(int e = s + 1;e <= k;e++)
            {
                dis[s][e] = min(dis[s][e],t[s] + t[e]);
                dis[e][s] = dis[s][e];
            }
        }
        */
    }

    //cout << "--------" << endl;

    for(int s = 1;s <= n;s++)
    {
        for(int e = s + 1;e <= n;e++)
        {
            dis[s][e] = INF;
            dis[e][s] = dis[s][e];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        dis[i][i] = 0;
    }
    for(int k = 1;k <= m;k++)
    {
        for(int i = 1;i <= cnt_line[k];i++)
        {
            for(int j = i + 1;j <= cnt_line[k];j++)
            {
                int xline = station[k][i];
                int yline = station[k][j];

                dis[xline][yline] = min(dis[xline][yline], station_time[k][i] + station_time[k][j]);
                dis[yline][xline] = dis[xline][yline];
            }
        }
    }
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                dis[i][j] = min(dis[i][k] + dis[k][j],dis[i][j]);
                dis[j][i] = dis[i][j];
            }
        }
    }

    //cout << "*********" << endl;

    for(int r = 1;r <= p;r++)
    {
        res = INF;

        int x,y;
        cin >> x >> y;
        if(x == y)
        {
            cout << 0 << endl;
            continue;
        }
        for(int i = 1;i <= cnt_line[x];i++)
        {
            for(int j = 1;j <= cnt_line[y];j++)
            {
                int xline = station[x][i];
                int yline = station[y][j];

                //cout << xline << " " << yline << endl;
                res = min(res,w[x] + station_time[x][i] + dis[xline][yline] + station_time[y][j] + w[y]);
            }
        }
        cout << res << endl;
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}
