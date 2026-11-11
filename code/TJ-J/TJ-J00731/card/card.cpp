#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+7, MAXM =3e5+7;
int n, m;
int a[MAXN], tot[MAXM];
bool exist[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	for(int i = 1;i <= n;++i){
		fill(exist+1, exist+m+1, 0);
		stack<int> st; 
		for(int j = i;j <= n;++j){
			if(exist[a[j]]){
				while(st.top() != a[j] && st.size())
					st.pop();
				if(st.size())	st.pop();
				exist[a[j]] = false;
			} else{
				st.push(a[j]);
				exist[a[j]] = true;
			}
		}
		while(st.size()){
			tot[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;++i){
		cout << tot[i] << ' ';
	}
	return 0;
} 


