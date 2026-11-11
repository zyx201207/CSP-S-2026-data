#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		stack<int> st;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			}else{
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}