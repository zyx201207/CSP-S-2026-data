#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int cnt[300005];
bool A = true;
void f(int s){
	set<int>se;
	stack<int>st;
	for(int i = s; i <= n; i++){
		if(se.count(a[i])){
			while(st.top() != a[i]){
				se.erase(st.top());
				st.pop();
			}
		}else{
			st.push(a[i]);
			se.insert(a[i]);
		}
	}
	for(auto shu : se){
		cnt[shu]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > a[i - 1])A = false;
	}
	if(n <= 5000){
		for(int i = 1; i <= n; i++){
			f(i);
		}
		for(int i = 1; i <= m; i++){
			cout << cnt[i] << " ";
		}
	}else if(A){
		for(int i = 1; i <= n; i++){
			cnt[a[i]]++;
		} 
		for(int i = 1; i <= m; i++){
			cnt[i] += cnt[i - 1];
			cout << cnt[i] << " ";
		}
	}else{
		int jishu = 0;
		a[0] = a[1] - 1;
		for(int i = 1; i <= n; i++){
			if(a[i] != a[i - 1]){
			    jishu++;
			}
			cnt[a[i]] += jishu;
		}
		for(int i = 1; i <= m; i++){
			cout << cnt[i] << " ";
		}
	} 
	return 0;
}
