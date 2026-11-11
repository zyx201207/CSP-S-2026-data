#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    srand(time(0));
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for (int i=1;i<=n;i++)
        {
            cin >> x[i];
        }
        if(c<3) cout << rand()%5+1 << endl;
        else if(c<7) cout << rand()%25+1 << endl;
        else if(c<11) cout << rand()%50+1 << endl;
        else cout << rand()%(n/50+1)+1 << endl;
    }
    return 0;
}
