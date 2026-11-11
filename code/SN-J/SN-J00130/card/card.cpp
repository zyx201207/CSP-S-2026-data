#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[500005];
int cnt[300005];
stack<int> st;
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int j = 1;j <= n;j++){
		for(int i = j - 1;i < n;i++){
			if(vis[a[i]]){
				while(st.top() != a[i]){
					vis[st.top()] = 0;
					st.pop();
				}
			}else{
				st.push(a[i]);
				vis[a[i]] = 1;
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}

	return 0;
} 
