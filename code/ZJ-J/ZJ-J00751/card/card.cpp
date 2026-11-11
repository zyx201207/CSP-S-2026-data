#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[500010],vis[300010];
deque <int>e[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		e[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int mi=i;
		for(int j=i;j<=n;j++){
			if(j!=e[a[j]].back())mi=max(mi,e[a[j]].back());
		}
		for(int j=mi;j<=n;j++){
			t[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<' ';
	return 0;
}