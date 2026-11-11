#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+1,0);
    int sum=0;
    for(int i=1;i<=m;i++){int x;cin>>x;sum+=x;}
    while(q--) cout<<sum;
}