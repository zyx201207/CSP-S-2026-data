#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N],ans[N];
bool vis[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int k = 1;k<=n;k++){
		while(!st.empty()) st.pop();
		memset(vis,0,sizeof vis);
		for(int i = k;i<=n;i++){
			if(vis[a[i]]){
				while(!st.empty()&&st.top()!=a[i]){
					vis[st.top()]=0;
					st.pop();
				}
			}
			else{
				st.push(a[i]);
				vis[a[i]]=1;
			}
		}
		while(!st.empty()){ans[st.top()]++;st.pop();}
	}
	for(int i = 1;i<m;i++) cout<<ans[i]<<" ";
	cout<<ans[m];
	return 0;
}

