#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int s[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>s[i];
        cout<<s[3]-d<<'\n';
    }
    return 0;
}
