#include<bits/stdc++.h>
using namespace std;
int n,ans,m,a[200005];
priority_queue<int>q;
void check(int id){
	int cx=a[id];
	for(int i=1;i<=n;++i){
		if(i!=id)q.push(a[i]&a[id]);
	}
	for(int i=1;i<m;i++){
		cx=cx&q.top();
		q.pop();
	}
	while(q.size())q.pop();
	ans=max(ans,cx);
//	if(cx>ans)return 1;
//	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			check(i);
		}
		cout<<ans;
	}
	
	return 0;
}
