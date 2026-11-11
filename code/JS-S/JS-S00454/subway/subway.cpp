#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c , n  , m , d , q;
    cin  >> c >> n >> m >> d >> q;
    long long  v[1010]={};
    for(int i  = 1; i <= m ; i ++)
    {
        cin >> v[i];
    }
    long long f[1010][1010]={};
    //memset(f,sizeof(f),0x3f);
    for(int i = 1 ; i<= m ; i ++)
    {
        for(int j = 1; j <=  m ; j ++)
        {
            f[i][j]=214748564800000;
        }

    }

    for(int i = 1; i <= n ; i ++)
    {
        long long k;
        cin >> k;
        long long to[10010]={},t[1010]={};
        for(int j = 1; j <= k ; j ++)
        {
            cin >> to[j] ;
            cin >> t[j];
            //cout << to[i] << " ";
        }

        for(int j = 1 ;j <= k ; j ++)
        {
            for(int j2 = j+1 ; j2 <= k ; j2++)
            {
                   // << j << " " << j2 << endl;
                  // cout << t[j] << " "<< t[j2] << endl;
              //  cout << f[to[j]][to[j2]] << " " << t[j]+t[j2] << endl;
                f[to[j]][to[j2]]=min(f[to[j]][to[j2]],t[j]+t[j2]);
                f[to[j2]][to[j]]=f[to[j]][to[j2]];

            }
        }
    }

    for(int i = 1; i<= m ; i ++)
    {
        f[i][i]=0;
    }
    for(int k = 1;k <= m ;k++)
    {
        for(int i = 1; i <= m ;i ++)
        {
            for(int j = i+1 ; j <= m ; j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                f[j][i]=f[i][j];
            }
        }
    }
     /*for(int i = 1 ; i<= m ; i ++)
    {
        for(int j = 1; j <=  m ; j ++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }*/
    for(int i = 1; i <= q; i++)
    {
        int a , b ;
        cin >> a >> b ;
        long long ans = f[a][b]+v[a]+v[b];
        cout << ans  << endl;
    }
    return 0;
}
