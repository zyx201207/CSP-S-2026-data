#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];

void solve1() {cout<<n;}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (m==1) solve1();

    return 0;
}
