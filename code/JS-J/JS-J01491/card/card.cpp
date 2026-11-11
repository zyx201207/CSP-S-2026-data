#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],res[M],cnt[M],lst[M];
vector<int> g[M];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        lst[a[i]]=i;
        if(a[i]<a[i-1]) flag=0;
    }
    if(flag)
    {
        for(int i=1;i<=m;i++) cout<<lst[i]<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int t=i;
        while(t<=n)
        {
            res[a[t]]++;
            t=lst[a[t]]+1;
        }
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<' ';
	return 0;
}
