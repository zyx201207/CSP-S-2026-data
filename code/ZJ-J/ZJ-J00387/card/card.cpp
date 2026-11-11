#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
bool vis[M];
int n,m,cnt[M],a[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(!vis[a[i]]){
				vis[a[i]]=true;
				st.push(a[i]);
			}else{
				while(true){
					if(st.top()==a[i]) break;
					else{
						vis[st.top()]=false;
						st.pop();
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) cnt[i]++;
		}
		while(true){
			if(st.empty()) break;
			st.pop();
		}
		memset(vis,false,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
