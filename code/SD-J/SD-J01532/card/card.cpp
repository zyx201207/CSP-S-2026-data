#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[300010],xb;
//int cnt;
bool vis[300010];
queue<int> q; 
stack<int> st; 
int main(){
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		//for(int j=1;j<=n;j++) q.push(a[j]);
		xb=i;
		memset(vis,0,sizeof(vis));
		//cnt=n;
		while(xb<=n){
			if(vis[a[xb]]){
				while(!st.empty() && st.top()!=a[xb]){
					vis[st.top()]=0;
					st.pop();
				}
				if(!st.empty() && st.top()==a[xb]) st.pop();
			}
			else vis[a[xb]]=1;
			st.push(a[xb]);
			xb++;
		}
		while(!st.empty()){
			st.pop();
		}
		for(int i=1;i<=m;i++){
			ans[i]+=vis[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

