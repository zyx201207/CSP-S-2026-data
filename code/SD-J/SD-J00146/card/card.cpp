#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[300004];
long long p[300004];
long long nxt[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(p,-1,sizeof(p));
	memset(nxt,-1,sizeof(nxt));
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long long i=1; i<=n; i++) {
		if(p[a[i]]==-1)
		{
			p[a[i]]=i;
		}else{
			nxt[p[a[i]]]=i;
			p[a[i]]=i;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		long long pos=i;
		while(pos<=n)
		{
			if(nxt[pos]!=-1)
			{
				pos=nxt[pos];
			}else{
				ans[a[pos]]++;
				pos++;
			}
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}

