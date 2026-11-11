//考号:SN-J00796 学校：西安市临潼区铁炉初级中学 姓名：孙博元 
#include<bits/stdc++.h>
using namespace std;
int a[20005];
int n,m;
long long ans;
bool vis[20005];
void dfs(int x,int step,long long y){
	if(step==m){
		ans = max(ans,y);
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(i,step+1,(y&a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in", "r" , stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,1,a[i]);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
