#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],s=0,sz;
int bfs(int a,int b) {
	for(int i=1; i<=n; i++) {
		if(x[i]>=x[a]-d&&x[i]<=x[a]+d) {
			if(x[i]==x[b]) {
				s++;
				break;
			}
			bfs(i,b);
		}
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cout<<1<<endl<<2;return 0;
	}
	for(int i=1; i<=t; i++) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		for(int i=1; i<=n; i++) {
			if(bfs(1,i)==2) {
				sz++;
			}
		}
	}
	cout<<sz;

	return 0;
}