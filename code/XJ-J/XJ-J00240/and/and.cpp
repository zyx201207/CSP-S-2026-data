#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],ans,vis[N];
void  dfs(int len,int num,int st){
	if(len==m){
		ans=max(num,ans);
		return;
	}
	for(int i=st;i<=n;i++){
		if(len==0){
			num=a[i];
			vis[len]=num;
			dfs(len+1,num,st=i+1);
		}else{
			if(vis[len]>num&a[i])continue;
			vis[len]=num&a[i];
			dfs(len+1,num&a[i],st=i+1);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,1);
	cout<<ans;
	return 0;
}

/*
5 3
31 3 1 15 7
*/























