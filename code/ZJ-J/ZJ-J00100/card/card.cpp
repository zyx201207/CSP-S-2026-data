#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
const int M = 3e5 + 100;
int a[N];
int tong1[M];
int tong2[M];
signed main(){
	//O(n^2)
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//card
	int n,m; cin >> n >>m;
	for(int i = 1; i <= n; i++) cin >>a[i];
	for(int i = 1; i <= n; i++){
		memset(tong1,0,sizeof(tong1));
		vector<int> v;//出牌序列 
		stack<int> st;//维护桌面上的牌
		for(int j = i; j <= n; j++) v.push_back(a[j]);
		//cout << "Now\n";
		for(int j = 0; j < v.size(); j++){
			int now = v[j];
			//cout <<now << ' ';
			if(tong1[now]){
				while(!st.empty() && st.top() != now){
					tong1[st.top()]--;
					st.pop();
				}
				st.pop();
				tong1[now]--;
			}
			st.push(now);
			tong1[now]++;
		}
		//cout <<"\nST: ";
		while(!st.empty()){
			tong2[st.top()]++;
			//cout <<st.top() <<' ';
			st.pop();
		}
		//cout <<'\n';
		//for(int i = 1; i <= m; i++) cout << tong2[i] << ' ';
		//cout <<'\n';
	}
	for(int i = 1; i <= m; i++) cout << tong2[i] << ' ';
}
