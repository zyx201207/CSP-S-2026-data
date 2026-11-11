#include<bits/stdc++.h>
using namespace std;
long long many,nxz,a[200010],maxn=0;
bool vis[200010];
void dfs(long long sum,long long num,long long u){
	if(sum==nxz){
		maxn=max(maxn,num);
		return;
	}else{
		for(int i=u;i<=many;i++){
			if(vis[i]!=true){
				vis[i]=true;
				if(sum==0){
				dfs(sum+1,a[i],i);			
				}else{
					dfs(sum+1,(num&a[i]),i);
				}
				vis[i]=false;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>many>>nxz;
	if(many<=1||nxz<=1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=many;i++){
		cin>>a[i];
	}
	dfs(0,0,1);
	cout<<maxn;
	return 0;
}
