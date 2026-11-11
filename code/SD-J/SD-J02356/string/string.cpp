#include<iostream>
#include<queue>
#define int long long

struct Node{
	int len;
	char flag;
};

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	std::cin>>n;
	std::deque<Node> q;
	while (n--) {
		int a;
		char c;
		std::cin>>a>>c;
		q.push_back({a, c});
	}
	int cnt=0;
	while (q.size()>1) {
		const int l1=q.front().len, l2=q.back().len;
		const char c1=q.front().flag, c2=q.back().flag;
		q.pop_front(), q.pop_back();
		const int min=std::min(l1, l2);
		if (c1!=c2)
			cnt+=min;
		if (l1!=min) 
			q.push_front({l1-min, c1});
		else if (l2!=min)
			q.push_back({l2-min, c2});
	}
	std::cout<<cnt;
	return 0;
}
