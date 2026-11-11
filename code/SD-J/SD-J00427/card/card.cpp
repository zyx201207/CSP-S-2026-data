#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10,M = 3e5;
int a[N],ans[N];
int b[M];

stack<int> st;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int k = 1;k <= n;k++){
		//cout << k << "\n";
		for(int i = k;i <= n;i++){
			//cout <<  a[i] << ' ';
			if(b[a[i]] == 0){
				st.push(a[i]);
				//cout << st.top();
				b[a[i]] = i;
			}
			else{
				while(st.top() != a[i]){
					b[st.top()] = false;
					//cout << st.top() << ' ';
					st.pop();
				}
			}
		}
		//cout << "\n";
		while(st.empty()){
			//cout << st.top();
			ans[b[st.top()]] ++;
			st.pop();
		}
		//cout << "\n";
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
