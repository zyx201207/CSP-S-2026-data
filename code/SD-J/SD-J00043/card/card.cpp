#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],vis[500010],js[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	stack<int>st;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[j]==0)vis[a[j]]=j,st.push(a[j]);
			else{
				for(int k=vis[a[j]];k<=j;k++)st.pop();
				st.push(a[j]);
				vis[j]=0;
			}
		}
		while(!st.empty()){
			js[st.top()]++;
			st.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++)cout<<js[i]<<" ";
	return 0;
}

