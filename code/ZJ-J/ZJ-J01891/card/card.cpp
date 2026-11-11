#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],ans[N];
bool vis[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> st;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==true){
				while(st.top()!=a[j]){
					vis[st.top()]=false;
					st.pop();
				}
			}else{
				vis[a[j]]=true;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
