#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> s1;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				s1.push(a[j]);
			}else{	
				int t=s1.top();
				while(t!=a[j]&&!s1.empty()){
					s1.pop();
					vis[t]=0;
					t=s1.top();
				
				}
			}
		}
		while(!s1.empty()){
			int t=s1.top();
			cnt[t]++;
			s1.pop();
		}
	
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}