#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<int> p;
set<int> s;
stack<int> ck;
map<int, int> mp;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		p.push(tmp);
	}
		for(int i=1; i<=n; i++){
			s.clear();
			while(!ck.empty()){
				ck.pop();
			}
			queue<int> nw = p;
			for(int j=0; j<i; j++){
				nw.pop();
			}
			while(!p.empty()){
				int tmp = p.front();
				p.pop();
				if(s.count(tmp)>0){
					while(ck.top()!=tmp){
						s.erase(ck.top());
						ck.pop();
					}
				}else{
					s.insert(tmp);
					ck.push(tmp);
				}
			}
			for(int d : s){
				mp[d]++;
			}
		}
		for(int i=1; i<=m; i++){
			cout << mp[i] << ' ';
		}
}
