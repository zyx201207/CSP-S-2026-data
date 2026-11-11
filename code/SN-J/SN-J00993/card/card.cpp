#include<bits/stdc++.h>
using namespace std;
int n,m;
deque<int> a;
stack<int> p;
set<int> chack;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		p.push(x);
		chack.get(x);
	}
	return 0;
}
