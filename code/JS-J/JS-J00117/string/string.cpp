#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
struct node{
	int x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	queue<node>q,w;
	for(int i=1;i<=n/2;i++){
		q.push(a[i]);
		w.push(a[n-i+1]);
	}
	if(n%2){
		q.push({a[n/2+1].x/2,a[n/2+1].c});
		w.push({a[n/2+1].x/2,a[n/2+1].c});
	}
	while(!q.empty()&&!w.empty()){
		int l=min(q.front().x,w.front().x);
		if(q.front().c!=w.front().c)ans+=l;
		if(q.front().x==l)q.pop();
		if(w.front().x==l)w.pop();
	}
	cout<<ans;
	return 0;
}
