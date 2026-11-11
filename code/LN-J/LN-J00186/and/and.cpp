#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans=INT_MIN;
void dfs(int x,int cnt,int cur){
	if(cur>m)return ;
	if(x==n+1){
		if(cur<m)return;
		ans=max(ans,cnt);
		return ;
	}
	dfs(x+1,cnt,cur);
	dfs(x+1,cnt&a[x],cur+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int maxn=INT_MIN,y;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i==1)y=a[i];
		else    y&=a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<y;
		return 0;
	}
	if(m==2){
		int maxn=INT_MIN;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	dfs(1,2147483647,0);
	cout<<ans;
	return 0;
}
