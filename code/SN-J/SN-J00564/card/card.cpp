//SN-J00564
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int t[300010];
bool vis[300010];
stack <int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int k=1;k<=n;k++){
		memset(vis,0,sizeof(vis));
		for(int i=k;i<=n;i++){
			if(vis[a[i]]==0){
				st.push(a[i]);
				vis[a[i]]=1;
			}else{
				int now=0;
				while(now!=a[i]){
					now=st.top();
					st.pop();
					vis[now]=0;
				}
				vis[a[i]]=1;
				st.push(a[i]);
			}
		}
		while(!st.empty()){
			t[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",t[i]);
	return 0;
}
