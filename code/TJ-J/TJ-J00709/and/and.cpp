#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],ans;
struct node{
	int j,step,i;
};
void bfs(int j,int i){
	queue<node> q;
	q.push({j,1,i});
	while(!q.empty()){
		node head=q.front();
		q.pop();
		if(head.step==m){
			ans=max(ans,head.j);
		}
		for(int i=head.i+1;i<=n;i++){
			q.push({(head.j&a[i]),head.step+1,i});
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) bfs(a[i],i);
	cout<<ans;
	return 0;
}
