#include<bits/stdc++.h>//card
using namespace std;
int n,m,a[500005];
stack<int> st;
map<int,int> mp;
bool vis[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				st.push(a[j]);
			}else{
				while(!st.empty()){
					int x=st.top();
					st.pop();
					vis[x]=0;
					if(x==a[j]) break;
				}
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!st.empty()){
			int x=st.top();
			st.pop();
			mp[x]++;
		}
	}
	for(auto x:mp){
		cout<<x.second<<" ";
	}
	return 0;
}
