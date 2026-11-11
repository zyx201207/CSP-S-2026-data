#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[500005];
bool p[300005];
int s[300005];
stack<int> q;
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(!q.empty()){
		q.pop();
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int l = 1; l <= n; l++){
		for(int i = 1; i <= m; i++){
			p[i] = false;
		}
		for(int i = l; i <= n; i++){
			if(!p[a[i]]){
				q.push(a[i]);
				p[a[i]] = true;
			}else{
				while(!q.empty()){
					if(q.top() != a[i]){
						p[q.top()] = false;
							q.pop();
					}else{
						break;
					}
				}
				q.pop();
				q.push(a[i]);
			}
		}
		while(!q.empty()){
			s[q.top()]++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++){
		cout << s[i] << ' ';
	}
	return 0;
}
