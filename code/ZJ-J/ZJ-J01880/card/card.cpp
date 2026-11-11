#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans[300001];
bool vis[300001];
int a[50001];
void sol(int num){
	stack<int >s;
	memset(vis,0,sizeof(vis));
	for(int i=num;i<=n;i++){
		if(!vis[a[i]]){
			s.push(a[i]);
			vis[a[i]]=1;
		}else{
			int u=0;
			while(1){
				u=s.top();
				if(u==a[i]) break;
				else{
					vis[u]=0;
					s.pop();
				}
			}	
		}
	}
	while(!s.empty()){
		int u=s.top();
		ans[u]++;
		s.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		sol(i);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
