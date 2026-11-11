#include<bits/stdc++.h>
using namespace std;
int a[500005];
int t[300005];
int vis[300005];
int ans[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		stack<int>st;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!st.empty()&&st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			}else{
				vis[a[j]]=1;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

