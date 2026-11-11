#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl '\n'
#define mk make_pair
int n,x;
ll cnt;
char c;
deque<pair<int,char>> dq;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x>>c;
		dq.push_back(mk(x,c));
	}
	while (!dq.empty()){
		if (dq.front().second!=dq.back().second){
			cnt+=min(dq.front().first,dq.back().first);
		}
		if (dq.front().first<dq.back().first){
			x=dq.back().first-dq.front().first;
			c=dq.back().second;
			dq.pop_back();
			dq.pop_front();
			dq.push_back(mk(x,c));
		}else if(dq.front().first>dq.back().first){
			x=dq.front().first-dq.back().first;
			c=dq.front().second;
			dq.pop_back();
			dq.pop_front();
			dq.push_front(mk(x,c));
		}else{
			dq.pop_front();
			if (!dq.empty()){
				dq.pop_back();
			}
		}
	}
	cout<<cnt;
	return 0;
} 
