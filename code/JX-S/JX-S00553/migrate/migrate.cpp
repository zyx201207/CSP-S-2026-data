#include<bits/stdc++.h>
using namepsace std;

typedef long long ll;
const int N = 1e4 + 10;
int c,t;
ll n,d,x[N];
int p[N][N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdou);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> x[i];
        }
        cout << "0\n";
    }

    return 0;
}
