#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,a[2000009],cnt[2000009],ans,v[2000009];

struct Node {
	long long id,k;
	friend bool operator< (Node q1,Node q2) {
		if(q1.k!=q2.k) {
			return q1.k>q2.k;
		} else {
			return q1.id>q1.id;
		}
	}
};

void bfs(long long x) {
	priority_queue<Node> q;
	q.push(Node {x,0});
	while(!q.empty()) {
		Node p=q.top();
		q.pop();
		long long id=p.id,k=p.k;
		if(v[id]) {
			if(k==v[id]) {
				cnt[id]++;
			} else {
				continue;
			}
		}
		v[id]=k;
		long long j=id+1;
		while(a[id]+d>=a[j]&&j<=n) {
			q.push(Node {j,k+1});
			j++;
		}
	}
	return;
}

void solve1() {
	for(long long i=1; i<=n; i++) {
		memset(v,0,sizeof(v));
		memset(cnt,0,sizeof(cnt));
		bfs(i);
		for(long long j=i+1; j<=n; j++) {
			if(cnt[j]==1) {
				ans++;
			}
		}
	}
	return;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--) {
		scanf("%lld %lld",&n,&d);
		for(long long i=1; i<=n; i++) {
			scanf("%lld ",&a[i]);
		}
		if(n<=3) {
			printf("0\n");
			continue;
		}
		bool b=true;
		long long t=a[2]-a[1];
		for(long long i=3;i<=n;i++){
			if(a[i]-a[i-1]!=t){
				b=false;
				break;
			}
		} 
		ans=0;
		if(b==false) {
			solve1();
		} else {
			if(a[3]-a[1]<=d) {
				ans=n-d/(a[2]-a[1])*2+1;
				ans=max((long long)0,ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
