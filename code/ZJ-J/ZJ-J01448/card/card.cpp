#include <bits/stdc++.h>
using namespace std;
using pii = pair<int ,int>;
const int M = 3e5 + 5;
int s[M];
queue<int> g;
stack<int> k[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		int t;
		cin>>t;
		g.push(t);
	}
	for(int i = 1;i <= n;i++){
		s[i] = i;
	}
	for(int i = 1;i <= m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}