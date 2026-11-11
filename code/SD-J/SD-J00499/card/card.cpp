#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[500005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int> s;
	for(int i=1;i<=n;i++){
		stack<int> s;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){	
			if(vis[a[j]]==0){
				s.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){	
			if(vis[j]==1){
				ans[j]++;
			}	
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
