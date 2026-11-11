#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=0;
int vis[200005];
int dfs(int sum,int cnt){
	if(cnt==0)   return ans=max(ans,sum);
	
	for(int i=1;i<=n;i++){
		int b=sum;
		if(vis[i]==1)   continue;
		vis[i]=1;
		sum=(sum&a[i]);
		dfs(sum,cnt-1);
		sum=b;
		vis[i]=0;
	}
	
	return ans;
}



int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			cnt=(cnt&a[i]);
		}
		cout<<cnt;
	}else{
		cout<<dfs(536870911,m); 	
	}
	return 0;

} 
