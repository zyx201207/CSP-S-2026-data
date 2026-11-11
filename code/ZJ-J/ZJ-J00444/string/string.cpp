#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

stack< pair<long long, char> > s;
queue< pair<long long, char> > q;

int main(){
	
	ios::sync_with_stdio(false);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		long long x;
		char c;
		cin >> x >> c;
		s.push({x, c});
		q.push({x, c});  
	}
	
	while(!s.empty()){
		long long x1 = s.top().first;
		char c1 = s.top().second; 
		long long x2 = q.front().first;
		char c2 = q.front().second;
		if(c1 == c2){
			if(x1 == x2){
				s.pop();
				q.pop();
			}else if(x1 > x2){
				s.top().first -= x2;
				q.pop();
			}else{
				s.pop();
				q.front().first -= x1;
			}
		}else{
			if(x1 == x2){
				ans += x1;
				s.pop();
				q.pop();
			}else if(x1 > x2){
				ans += x2;
				s.top().first -= x2;
				q.pop();
			}else{
				ans += x1;
				s.pop();
				q.front().first -= x1;
			}
		}
	}
	
	cout << ans / 2 << "\n";
	
	return 0;
}
