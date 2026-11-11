#include<bits/stdc++.h>

using namespace std;

struct uu{
	string s;
	long long a;
}a[200010];
int n,m;
queue<uu> q,p;
long long h;
long long u(int i) {
	long long t=pow(2,i);
	return t;
}
bool cmp(uu x,uu y) {
	return x.s>y.s;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i].a;
		long long aa=a[i].a;
		for(int j=29;j>=0;j--) {
			long long t=u(j);
			if(aa>=t) {
				aa-=t;
				a[i].s+='1';
			} 
			else a[i].s+='0';
		}
		q.push({a[i].s,a[i].a});
	}
	for(int i=0;i<=29;i++) {
		int cnt=0;
		while(!q.empty()) {
			uu u=q.front();q.pop();
			if(u.s[i]=='1') cnt++;
			p.push({u.s,u.a});
		}
		if(cnt<m) {
			while(!p.empty()) {
				uu u=p.front();p.pop();
				q.push({u.s,u.a});
			}
			continue;
		}
		while(!p.empty()) {
			uu u=p.front();p.pop();
			if(u.s[i]=='1') q.push({u.s,u.a});
		}
	}
	h=q.front().a;q.pop(); 
	for(int i=2;i<=m;i++) {
		h&=q.front().a;q.pop();
	}
	cout<<h;
	return 0;
}
