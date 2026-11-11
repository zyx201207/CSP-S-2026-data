#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],now[300005],ans[300005];
stack<int> st;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int k=a[j];
			if (now[k]){
				while (!st.empty() && a[st.top()]!=k){
					now[a[st.top()]]--;
					st.pop();
				}
				if (!st.empty()){
					now[k]--;
					st.pop();
				}
			}
			st.push(j);
			now[k]++;
		}
		while (!st.empty()){
			ans[a[st.top()]]++;
			now[a[st.top()]]--;
			st.pop();
		}
	}
	for (int i=1;i<=m;i++) cout << ans[i] << ' ';
	return 0;
}
