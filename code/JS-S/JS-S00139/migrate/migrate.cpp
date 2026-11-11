#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int c,t;
int x[maxn];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        int n,d;
        cin >> n >> d;
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++)
        {
            cin >> x[i];
        }
        int cha=x[2]-x[1];
        int ans=(d/cha);
        int fin=0;
        for(int i=ans+1;i<=ans*2;i++)
        {
            if(i<4) continue;
            fin+=(n-i+1);
        }
        cout << fin << endl;
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
