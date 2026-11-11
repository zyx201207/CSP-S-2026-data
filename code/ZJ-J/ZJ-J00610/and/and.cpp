#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[200005],ans,used[4000005],boo=0,b2=0;
void dfs(int id,int cnt,int sum){
	if(id>n+1)
		return;
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	dfs(id+1,cnt+1,sum&a[id]);
	dfs(id+1,cnt,sum);
}
void f(){
	for(int i=1;i<=n;i++){
		dfs(i,0,a[i]);
	}
	cout<<ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=21;i++){
		used[(int)pow(2,i)]=1;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)
			boo=1;
		if(!used[a[i]+1])
			b2=1;
	}
	if(used[n]&&!boo){
		sort(a+1,a+1+n,cmp);
		int x=a[1];
		for(int i=1;i<=m;i++){
			x&=a[i];
		}
		cout<<x;
	}
	else if(!b2){
		sort(a+1,a+1+n,cmp);
		int x=a[1];
		for(int i=1;i<=m;i++){
			x&=a[i];
		}
		cout<<x;
	}
	else
		f();
	return 0;
}
