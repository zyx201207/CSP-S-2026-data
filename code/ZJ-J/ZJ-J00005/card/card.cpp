#include<bits/stdc++.h>

using namespace std;

struct node{
	long long num, x;
}b[500010];

int n, m;

int a[500010];
long long ret2[500010];
long long ret[500010];

int lst[300010];

void solve1(){
	for(int i = 1; i <= n; i++){
		lst[a[i]] = i;
	}
	for(int i = 1; i <= m; i++){
		cout << lst[i] << " ";
	}
}

int vis2[300010];
int vis[300010];
bool can[3010][5010];

stack<int> st;
stack<int> tmp;

void solve2(){
	long long ret1 = 0;
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= m; k++){
				vis2[k] = 0;
			}
			while(!st.empty()){
				st.pop();
			}
			for(int k = j; k <= n; k++){
//				cout << k << "!";
				if(vis2[a[k]] == 1){
					while(!st.empty() && st.top() != a[k]){
						vis2[st.top()] = 0;
						st.pop();
					}
					if(!st.empty()){
						vis2[st.top()] = 0;
						st.pop();
					}
					
				}
				vis2[a[k]] = 1;
				st.push(a[k]);
			}
			while(!st.empty()){ 
//				cout << st.top() << " ";
				ret2[st.top()]++;
				st.pop();
			}
		}
		for(int i = 1; i <= m; i++){
			cout << ret2[i] << ' ';
		}
}

void solve3(){
	if(a[n] == 1){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 2){
				cnt++;
			}
		}
		cout << n << " " << cnt;
	}else{
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				cnt++;
			}
		}
		cout << cnt << " " << n;
	}
	
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int f = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i != 1 && a[i] < a[i - 1]){
			f = 0;
		}
	}
	
//	for(int i = 1; i <= n; i++){
//		cout << b[i].num << " " << b[i].x << "\n";
//	}
	if(f == 1){
		solve1();
	}else if(n <= 5000 && m <= 3000){
		solve2();
	}else{
		solve3();
	}
	
	return 0;
}