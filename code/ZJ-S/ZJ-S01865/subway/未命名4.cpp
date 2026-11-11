#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<pair<int,int>,vector<int>,greater<pair<int,int>>()> qu;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	qu.push({5,2});
	qu.push({3,4});
	qu.push({3,2});
	cout<<qu.top().first;
	return 0;
}