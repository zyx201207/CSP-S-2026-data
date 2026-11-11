#include<bits/stdc++.h>
using namespace std;
const int N = 500001;
const int M = 200001;
int n,m,a[N],ans[M];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	stack<int> st;
    for (int i = 1;i <= n;i++){
        while (!st.empty()) st.pop();
        memset(vis,0,sizeof(vis));
        for (int j = i;j <= n;j++){
            if (vis[a[j]])
                while (st.top() != a[j]) {vis[st.top()] = 0;st.pop();}
            else {st.push(a[j]);vis[a[j]] = 1;}
        }
        while (st.size()){
            ans[st.top()]++;
            st.pop();
        }
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
    return 0;
}
