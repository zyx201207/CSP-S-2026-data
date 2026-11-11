#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m,i,x,now,len;
int num[N];
int H[40];
vector<int> a[40];
int lowbit(int x){
	return x&(-x);
}
void dfs(int u,int ans){
	int i,x,len,now,cnt=0;
	len=a[u].size();
	for(i=0;i<len;i++) num[++cnt]=a[u][i];
	for(i=0;i<=37;i++) a[i].clear();
	for(i=1;i<=len;i++){
		x=num[i];
		while(x){
			now=lowbit(x)%37;
			if(now==u) break;
			a[now].push_back(num[i]);
			x=x&(x-1);
		}
	}
	bool flag=0;
	for(i=ans-1;i>=0;i--){
		now=(1<<i)%37;
		len=a[now].size();
		if(len<m) continue;
		flag=1;
		dfs(now,i);
		break;
	}
	if(!flag){
		int res=num[1];
		for(i=2;i<=m;i++) res&=num[i];
		cout<<res;exit(0);
	}
	return ;
}
/*
5 3
31 3 1 15 7
*/
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>num[i];x=num[i];
		while(x){
			now=lowbit(x)%37;
			a[now].push_back(num[i]);
			x=x&(x-1);
		}
	}
	bool flag=0;
	for(i=30;i>=0;i--){
		now=(1<<i)%37;
		len=a[now].size();
		if(len<m) continue;
		flag=1;
		dfs(now,i); 
		break;
	} 
	if(!flag)cout<<0;
	return 0;
}
