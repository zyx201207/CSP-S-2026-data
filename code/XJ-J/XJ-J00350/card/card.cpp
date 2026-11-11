#include<bits/stdc++.h>
using namespace std;
int a[500010];
int t[300010];
int s[500010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int j=1; j<=n; j++) {
		queue<int>b;
		for(int i=j; i<=n; i++) {
			if(!t[a[i]])b.push(a[i]);
			queue<int>c;
			while(1) {
				c.push(b.front());
				if(b.front()==a[i])break;
				b.pop();
			}
			while(!b.empty())b.pop();
			while(!c.empty()) {
				b.push(c.front());
				c.pop();
			}
		}
		while(!b.empty()){
			s[b.front()]++;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}
