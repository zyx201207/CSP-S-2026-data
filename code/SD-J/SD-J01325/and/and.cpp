#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0;
bool b[200010][35];
void dfs(long long x,int i,int j){
	if(j==m){
		ans=max(ans,x);
		return ;
	}for(int s=i+1;s<=n;s++){
		if(x&a[s]>ans)
			dfs(x&a[s],s,j+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n-m+1;i++){
		if(a[i]>ans)
			dfs(a[i],i,1);
	}cout<<ans;
	return 0;
}

