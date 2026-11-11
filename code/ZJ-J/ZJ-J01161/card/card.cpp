#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],cnt[N],ans[N],to[N],in[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		to[a[i]]=a[i+1];
	}
	queue<int> qu;
	for(int i=1;i<=m;i++){
		in[to[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(!in[i]) qu.push(i);
	}
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		ans[u]+=cnt[u];
		in[to[u]]--;
		ans[to[u]]+=ans[u];
		if(to[u]!=0 && !in[to[u]]){
			qu.push(to[u]);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
}
