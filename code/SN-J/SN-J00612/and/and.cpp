#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n,m,a[N];

int dfs(int u,int s,int k){
	if(u>n){
		if(k==m)
			return s;
		else
			return 0;
	}	
	return max(dfs(u+1,s&a[u],k+1),dfs(u+1,s,k));
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		int ans;
		for(int i=1;i<=n;i++)
			ans=max(a[i],ans);
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
					ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=-1;
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
	}
	cout<<dfs(1,-1,0);
	return 0;
}
