#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	deque<pair<int, char>> q;
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x;
		char c; cin >> c;
		q.push_back({x, c});
	}
	long long ans = 0;
	while(!q.empty()) {
		pair<int, char> head;
		pair<int, char> tail;
		head = q.front();
		tail = q.back();
		if(head.second == tail.second) {
			if(head.first > tail.first) {
				q.front().first -= tail.first;
				q.pop_back();
			}
			else if(head.first < tail.first) {
				q.back().first -= head.first;
				q.pop_front();
			}
			else {
				q.pop_back();
				if(!q.empty())q.pop_front();
			}
		}
		else {
			if(head.first > tail.first) {
				q.front().first -= tail.first;
				ans += tail.first;
				q.pop_back();
			}
			else if(head.first < tail.first) {
				q.back().first -= head.first;
				ans += head.first;
				q.pop_front();
			}
			else {
				ans += head.first;
				q.pop_back();
				if(!q.empty())q.pop_front();
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}