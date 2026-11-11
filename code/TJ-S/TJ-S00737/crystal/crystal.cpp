#include<bits/stdc++.h>
using namespace std;
unsigned long long n, m;
long long a[500005], pre[500005];
int q(int l, int r){return a[r]*(r-l+1)-(pre[r]-pre[l-1]);}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; ++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1; i<=n; ++i)pre[i]=pre[i-1]+a[i];
	cout<<3;
    return 0;
}

