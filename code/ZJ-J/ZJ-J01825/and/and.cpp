#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=-1;
bool vis[200010];
void dfs(long long Step,long long cnt){
	if(Step==m){
		ans=max(ans,cnt);
		return ;
	}
	long long Cnt;
	Cnt=cnt;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(!Step) cnt=a[i];
			else cnt=(Cnt&a[i]);
			dfs(Step+1,cnt);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;	
}
