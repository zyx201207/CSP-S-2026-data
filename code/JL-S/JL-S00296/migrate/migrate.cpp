#include<bits/stdc++.h>
using namespace std ;

struct str{
    int dist ;
};

int x[1000] = {0} ;
vector<str> v[1000000] ;
int n, d, k ;


bool bfs(int u1, int v1)
{
    int q[1000000] = {0} ;
    int sum = 0, head = 0, tail = 0, minn = -1e9, l = 0;
    q[0] = u1 ;
    for(int i=head; i<=tail; i++)
    {
        int a = q[head] ;
        head++ ;
        if(a == v1)
        {
            if(minn <= sum)
            {
                if(minn == sum)
                {
                    l++ ;
                }
                else minn = sum ;
            }
        }
        for(int i=0; i<v[a].size(); i++)
        {
            sum += v[a][i].dist ;
            q[tail] = i ;
            tail++ ;
        }
    }
    if(l == 2) return true ;
    else return false ;
}

int main()
{
    freopen("mlgrate.in", "r", stdin) ;
    freopen("mlgrate.out", "w", stdout) ;
    int c, t, ans = 0 ;
    scanf("%d%d", &c, &t) ;
    while(t--)
    {
        //cin >> n >> d ;
        //for(int i=0; i<n; i++) cin >> x[i] ;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(x[j]-x[i] <= d)
                {
                    v[i].push_back((str){j});
                    k++ ;
                    v[i][k-1].dist = x[j] - x[i] ;
                }
            }
        }

        for(int i=0; i<n; i++)
        {

            for(int j=0; j<v[i].size(); j++) cout << v[i][j].dist << " " ;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(bfs(i, j)) ans++ ;
            }
        }
        cout << ans+t << endl ;
    }

    return 0 ;
}
