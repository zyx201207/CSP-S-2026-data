#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,num,sum;
deque<pair<ll,char>>q;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while(n--){
		cin >> num >> c;
		q.push_front({num,c});
	}
	while(!q.empty()){
		pair<ll,char> a=q.front();
		q.pop_front();
		if(q.empty()) break;
		pair<ll,char> b=q.back();
		q.pop_back();
		ll minn=min(a.first,b.first);
		if(a.second!=b.second) sum+=minn;
		if(a.first>b.first){
			q.push_front({a.first-minn,a.second});
		}else if(a.first<b.first){
			q.push_back({b.first-minn,b.second});
		}
	}
	cout << sum;
	return 0;
}
