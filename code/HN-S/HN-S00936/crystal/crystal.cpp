#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,M,a[500010],ans;
bool vis[500010];
void DFS(int cnt,int ave,int m){
	for(int i=1;i<=N;i++){
		int add;
		if(a[i]<ave){
			add=ave-a[i];
		}
		else{
			add=cnt*(a[i]-ave);
		}
		if(!vis[i]&&m>=add){
			vis[i]=true;
			DFS(cnt+1,max(a[i],ave),m-add);
			vis[i]=false;
		}
	}
	ans=max(ans,cnt);
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	for(int i=1;i<=N;i++){
		vis[i]=true;
		DFS(1,a[i],M);
		vis[i]=false;
	}
	cout<<ans;
	return 0;
}
