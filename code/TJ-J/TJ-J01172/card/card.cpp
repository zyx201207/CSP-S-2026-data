#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int n,m,a[500001],ans[300001];
bool vis[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n){
		stack<int> st={};
		memset(vis,0,sizeof(vis));
		rep(j,i,n){
			if(vis[a[j]]){
				while(st.top()!=a[j]) ans[st.top()]--,vis[st.top()]=0,st.pop();
			}else vis[a[j]]=1,st.push(a[j]),ans[a[j]]++;
		}
	}
	rep(i,1,m) cout<<ans[i]<<" ";
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

