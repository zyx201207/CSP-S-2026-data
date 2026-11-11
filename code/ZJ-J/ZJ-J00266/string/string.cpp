#include<bits/stdc++.h>
using namespace std;
struct node {
	int a;
	char c;
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	deque<node>p;
	for(int i=1; i<=n; i++) {
		int a;
		char c;
		cin>>a>>c;
		p.push_back({a,c});
	}
	long long sum=0;
	while(p.size()>1) {
		node u=p.front();
		p.pop_front();
		node v=p.back();
		p.pop_back();
		if(u.c!=v.c) {
			sum+=min(u.a,v.a);
		}
		if(u.a<v.a) {
			p.push_back({v.a-u.a,v.c});
		} else if(u.a>v.a) {
			p.push_front({u.a-v.a,u.c});
		}
	}
	cout<<sum;
	return 0;
}