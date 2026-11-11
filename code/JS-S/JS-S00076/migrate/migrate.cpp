#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[2000005],len;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i = 1;i <= n;i++) cin>>a[i];
        if(n == 1 || a[1] == a[2])
        {
            cout<<0<<'\n';
            continue;
        }
        len = d / (a[2] - a[1]);
        //cout<<d<<' '<<(a[2] - a[1])<<' '<<len<<'\n';
        if(len <= 1 || 2 * len - 1 > n - 1) cout<<0<<'\n';
        else cout<<(n - (2 * len - 1))<<'\n';
    }
    return 0;
}
