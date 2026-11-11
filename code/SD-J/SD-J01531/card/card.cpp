#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,m,a[N],lst[N],cnt[N],ans[N],vis[N],f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
	}
	if(f){
		for(int i=1;i<=n;i++) ans[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else{
		stack<int> st;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			for(int j=i;j<=n;j++){
				int k=vis[a[j]];
				while(k>0&&vis[a[j]]!=k-1){
					vis[st.top()]--;
					st.pop();
				}
				vis[a[j]]++;
				st.emplace(a[j]);
			}
			memset(vis,0,sizeof vis);
			while(!st.empty()){
				if(!vis[st.top()]) ans[st.top()]++;
				vis[st.top()]=1;
				st.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
