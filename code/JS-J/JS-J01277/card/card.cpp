#include<bits/stdc++.h>
using namespace std;
int a[500050];
int ans[500050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		bool vis[500050];
		for(int j=1;j<=m;j++)vis[j]=0;
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				s.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
				s.pop();
				s.push(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
