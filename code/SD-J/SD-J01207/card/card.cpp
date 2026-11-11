#include<bits/stdc++.h>
using namespace std;
	int a[500005],st[300005],n;
	pair<int,int> s[500005];
void w(int g) {
	for (int i=1;i<=500000;i++) s[i]={i,0};
	queue<int> q;
	for (int i=g;i<=n;i++) {
		s[i]={i,1};
		q.push(a[i]);
		if(s[a[i]].first!=0 && s[i].first==s[a[i]].first) {
			s[a[i]].second--;s[a[i]].first=0;
			for (int j=1;j<=i-s[a[i]].first;j++) q.pop();
			q.push(a[i]);
		}
	}
	while (q.size()) {
		int x=q.front(); q.pop();
		st[x]++;
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) w(i);
	for (int i=1;i<=m;i++) cout<<st[i]<<' ';
	
	
	return 0;
}
