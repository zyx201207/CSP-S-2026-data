#include<bits/stdc++.h>
using namespace std;
int n,m,a[500006],b[500006],vis[500006];
void f(int idx){
    stack<int> q;
	for(int i=idx;i<=n;i++){
		if(!vis[a[i]]){
			q.push(a[i]);
			vis[a[i]]=1;
		}else{
			while(q.top()!=a[i]){
				vis[q.top()]=0;
				q.pop();
			}
		}
	}
	while(!q.empty()){
		b[q.top()]++;
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof vis);
		f(i);
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
} 
