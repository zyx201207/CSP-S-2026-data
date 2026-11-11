#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(1)
        {
            int gc=a[2]-a[1];
            if(d<gc*2) cout<<"0\n";
            else cout<<n-d/gc<<'\n';
        }
    }
	return 0;
}
