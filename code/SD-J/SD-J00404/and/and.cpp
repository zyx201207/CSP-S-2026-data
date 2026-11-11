#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,m;
struct Node{
	int cnt;
	int ed;
	int son[3];
}t[6500005];
int cntt=0;
void modify(int k){
	int now=0;
	for(int i=30;i>=0;i--){
		int u=(k>>i)&1;
		if(!t[now].son[u]){
			cntt++;
			t[now].son[u]=cntt;
		}
		now=t[now].son[u];
		t[now].cnt++;
	}
	t[now].ed++;
	return ;
}
int merge(int u,int v){
	if(v==0){
		return u;
	}
	if(u==0){
		return v;
	}
	t[u].cnt+=t[v].cnt;
	t[u].ed+=t[v].ed;
	t[u].son[0]=merge(t[u].son[0],t[v].son[0]);
	t[u].son[1]=merge(t[u].son[1],t[v].son[1]);
	return u;
}
int query(){
	int now=0;
	int ra=0;
	for(int i=30;i>=0;i--){
		if(t[t[now].son[1]].cnt>=m){
//			cout<<t[t[now].son[1]].cnt<<" "<<m<<" "<<i<<'\n';
			ra+=(1<<i);
			now=t[now].son[1];
		}else{
			now=merge(t[now].son[1],t[now].son[0]);
		}
	}
	return ra;
}
signed main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	cin>>n>>m;
//	cout<<m<<'\n';
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		modify(x);
	}
	int ans=query();
	cout<<ans<<'\n';
	return 0;
}
