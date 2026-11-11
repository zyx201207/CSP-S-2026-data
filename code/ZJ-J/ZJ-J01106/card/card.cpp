#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,a[500010],f[500010],sum[500010];
queue<int>q,qjj;
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	cin>>n>>m;
	for(i=1; i<=n; i++)cin>>a[i];
	for(i=1; i<=n; i++) {
		memset(f,0,sizeof(f));
		while(q.size())q.pop();
		while(qjj.size())qjj.pop();
		for(j=i; j<=n; j++)
			if(f[a[j]]==0)q.push(a[j]),f[a[j]]=1;
			else {
				while(q.front()!=a[j]) {
					int now=q.front();
					qjj.push(now);
					q.pop();
				}
				while(q.size()) {
					f[q.front()]=0;
					q.pop();
				}
				while(qjj.size()) {
					int now=qjj.front();
					q.push(now);
					qjj.pop();
				}
				q.push(a[j]);
				f[a[j]]=1;
			}
		while(q.size()) {
			int now=q.front();
			sum[now]++;
			q.pop();
		}
	}
	for(i=1; i<=m; i++)cout<<sum[i]<<" ";
}