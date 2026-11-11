#include <bits/stdc++.h>
using namespace std;
struct node{
	long long num,v,w;
};
queue <node> q;
long long n,m,a[500005],ans=0;
void bfs(long long x,long long l,long long r){
	q.push({x,l,r});
	while(!q.empty()){
		node hd=q.front();
		q.pop();
		if(hd.num/(hd.w-hd.v+1)>=a[hd.w]){
			cout<<hd.w-hd.v+1;
			return;
		}
		q.push({hd.num-a[hd.v],hd.v+1,hd.w});
		q.push({hd.num-a[hd.w],hd.v,hd.w-1});
	}
	cout<<1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	ans+=m;
	sort(a+1,a+n+1);
	bfs(ans,1,n);
	return 0;
}
