#include<bits/stdc++.h>
#define N 200100
using namespace std;
int n,M;
int tr[N][3],idx,cnt[N],depth=-1;
void add(int x){
	int u=0,X=0,dep=0;
	cnt[u]++;
	while(x){
		X=(x&1);
		if(tr[u][X]==-1) tr[u][X]=++idx;
		u=tr[u][X];
		x>>=1;
		cnt[u]++;
		dep++;
	}
	depth=max(depth,dep);
}
long long query(){
	long long u=0,ans=0;
	stack<int> stk;
	if(cnt[tr[0][1]]>=M&&tr[0][1]!=-1){
		u=tr[u][1];
		stk.push(1);
		for(int i=1;i<=depth;i++){
			if(tr[u][1]==-1&&tr[u][0]==-1) break;
			if((cnt[tr[u][1]]<M||tr[u][1]==-1)&&tr[u][0]!=-1){
				u=tr[u][0];
				stk.push(0);
			}else if(cnt[tr[u][1]]>=M&&tr[u][1]!=-1){
				u=tr[u][1];
				stk.push(1);
			}else break;
		}
	}
	while(!stk.empty()){
		int t=stk.top(); stk.pop();
		ans<<=1; ans+=t;
	}
	if(cnt[tr[0][0]]<M||tr[0][0]==-1) return ans;
	u=tr[0][0];
	stk.push(0);
	long long ans2=0;
	for(int i=1;i<=depth;i++){
		if(tr[u][1]==-1&&tr[u][0]==-1) break;
		if((cnt[tr[u][1]]<M||tr[u][1]==-1)&tr[u][0]!=-1){
			u=tr[u][0];
			stk.push(0);
		}else if(cnt[tr[u][1]]>=M&&tr[u][1]!=-1){
			u=tr[u][1];
			stk.push(1);
		}else break;
	}
	while(!stk.empty()){
		int t=stk.top(); stk.pop();
		ans2<<=1; ans2+=t;
	}
	return max(ans2,ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(tr,-1,sizeof tr);
	cin>>n>>M;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		add(x);
	}
	cout<<query()<<'\n';
	return 0;
}
