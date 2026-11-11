#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010];
bool vis[300010];
stack<int>c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==true){
				while(c.top()!=a[j]){
					vis[c.top()]=false;
					c.pop();
				}
			}else{
				vis[a[j]]=true;
				c.push(a[j]);
			}
		}
		while(!c.empty()){
			b[c.top()]++;
			c.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}

