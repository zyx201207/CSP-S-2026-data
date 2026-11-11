//牟镇嘉 SN-J00847 西安汇知中学 
#include<bits/stdc++.h> 
using namespace std;
int n,m,a[510],ans[510],vis[510];
stack<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++ )cin>>a[i];
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof vis);
		for (int j=1;j<=n;j++){
			if(vis [a[i]]){
				while(st.top()!=a[i]){
					vis[st.top()]=0;
					st.pop();
				}
				vis[a[i]]=1;
			}
			else st.push(a[i]),vis[a[i]]=1;
		}
		while( st.empty()  ) ans[st.top()]++,st.pop();
	}
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
