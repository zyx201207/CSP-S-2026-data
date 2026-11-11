#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],t[N],vis[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				st.push(a[j]);
				vis[a[j]]++;
			}else{
				while(st.top()!=a[j]){
					int q=st.top();
					vis[q]--;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			st.pop();
		} 
		for(int j=1;j<=m;j++){
			if(vis[j]) t[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
