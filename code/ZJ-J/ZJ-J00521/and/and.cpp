#include<bits/stdc++.h>
using namespace std;
//#define fr(x) freopen(#x".in","r",stdin)
//#define fw(x) freopen(#x".out","w",stdout)
struct node{
	int s[2],num;
};
node tr[7000005];
int cnt;
void add(int x){
	int p=0;
	for(int i=29;i>=0;i--){
		int now=(bool)(x&(1<<i));
		if(!tr[p].s[now]){
			tr[p].s[now]=++cnt;
		}
		p=tr[p].s[now];
		tr[p].num++;
	}
}
int n,m;
int bfs(){
	queue<int> q0,q1,q2,q3;
	if(tr[0].s[0])q0.push(tr[0].s[0]);
	if(tr[0].s[1])q1.push(tr[0].s[1]);
	int ans=0;
	for(int i=29;i>=0;i--){
//		cout<<"===="<<i<<"====\n";
		int cnt=0;
		while(!q2.empty()){
			q0.push(q2.front());
			q2.pop();
		}
		while(!q3.empty()){
			q1.push(q3.front());
			q3.pop();
		}
		while(!q1.empty()){
//			cout<<q1.front()<<'\n';
			if(tr[q1.front()].s[0])q2.push(tr[q1.front()].s[0]);
			if(tr[q1.front()].s[1])q3.push(tr[q1.front()].s[1]);
			cnt+=tr[q1.front()].num;
			q1.pop();
		}
		if(cnt>=m){
			ans+=(1<<i);
			while(!q0.empty())q0.pop();
			continue;
		}
		while(!q0.empty()){
			if(tr[q0.front()].s[0])q2.push(tr[q0.front()].s[0]);
			if(tr[q0.front()].s[1])q3.push(tr[q0.front()].s[1]);
			q0.pop();
		}
	}
	return ans;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		add(x);
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<i<<' '<<tr[i].s[0]<<' '<<tr[i].s[1]<<' '<<tr[i].num<<'\n';
//	}
//	cerr<<1<<'\n';
	cout<<bfs();
	return 0;
}
/*
01 Trie.

if 1's sum >= m:
dou wang 1 de fang zou
else:
liang bian dou zou 
*/
