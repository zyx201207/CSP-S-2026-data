#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
/*====================*/
const int N=5e5+10;
int a[N],m,n; 
int ans[N];
bool tmp[N];
/*====================*/
void solve(void){
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	stack <int> st;
	for (int i=1;i<=n;i++){
		memset(tmp,0,sizeof tmp);
		for (int j=i;j<=n;j++){
			/*for (int k=1;k<=m;k++){
				cout << tmp[k] << " ";
			}
			cout << "\n";*/
			if (tmp[a[j]]){
				while(!st.empty() && tmp[a[j]]){
				//	cout << "pop " << st.top() << "\n";
					tmp[st.top()]=0;
					st.pop();
				}
			//	if (!st.empty()) st.pop();
			}
			st.push(a[j]);
		//	cout << "push " << st.top() << "\n";
			tmp[a[j]]=1;
		}
		while(!st.empty()){
			ans[st.top()]++;
		//	cout << "pop " << st.top()<< "\n";
			st.pop();
		}
	}
	for (int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
}
/*====================*/
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
	return 0;
}
/*10 3
3 1 2 1 3 2 3 1 2 1*/
