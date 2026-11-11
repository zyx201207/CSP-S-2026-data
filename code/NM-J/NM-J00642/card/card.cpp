#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		queue<int>q;
		queue<int>p;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				q.push(a[j]);
				vis[a[j]]=1;
			}else{
				while(!q.empty() && q.front() != a[j]){
					int x=q.front();
					p.push(x);
					q.pop();
				}
				while(!q.empty()){
					int x=q.front();
					q.pop();
					vis[x]=0;
				}
				while(!p.empty()){
					int x=p.front();
					q.push(x);
					p.pop();
				}
				q.push(a[j]);
				vis[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				b[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
