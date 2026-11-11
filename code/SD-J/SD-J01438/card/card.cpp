#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],liu[300005],vis[300005];
stack<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int turn=1;turn<=n;turn++){
		memset(vis,0,sizeof(vis));
		for(int j=turn;j<=n;j++){
			if(!vis[a[j]]){
				st.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				int p=0x7fffffff;
				while(p!=a[j]){
					p=st.top();
					vis[p]=0;
					st.pop();
				}
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i])liu[i]++;
		}
		while(!st.empty()){
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<liu[i]<<" ";
	}
	return 0;
}
