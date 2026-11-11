#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010],d[300010],n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=m; i++) {
		queue<int> q;
		int o[500010];
		for(int j=i; j<=n; j++) {
			b[a[j]]=0;
		}
		for(int j=i; j<=n; j++) {
			b[a[j]]++;
			if(b[a[j]]==2){
				while(!q.empty()&&q.front()!=a[j]){
					b[q.front()]--;
					q.pop();
				}
				b[q.front()]--;
				q.pop();
			}
			q.push(a[j]);
		}
		for(int j=i; j<=m; j++) {
			if(b[a[j]]){
				d[a[j]]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<d[a[i]]<<" ";
	}

	return 0;
}
