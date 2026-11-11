#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool vis[300010];
int a[500010];
int ans[300010];
int b[500010]; 
bool check(){
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i]!=a[i]){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(check()){
		for(int i=1;i<=n;i++){
			cout<<n-i+1<<" ";
		}
		return 0;
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
			}
			else{
				st.push(a[j]);
				vis[a[j]]=1;	
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			//cout<<st.top()<<" ";
			st.pop();
		}
		//cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
