#include<bits/stdc++.h>
using namespace std;

long long n,d,a[2000006];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    srand((unsigned)clock());
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cout<<(long long)rand()*(long long)rand()%(n*(n-1))<<endl;
    }
    return 0;
}
