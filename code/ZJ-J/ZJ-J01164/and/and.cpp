#include<bits/stdc++.h>
using namespace std;
int a[200005];
int m,n,maxn=-1,s=1<<30-1;
int ans;
void dfs(int x,int sum,int l){
	if(x=m+1){
		ans=max(ans,sum);
		return;		
	}
	for(int i=l+1;i<=n;i++){
		dfs(x+1,sum^a[i],i);		
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		s^=a[i];
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(2,a[i],i);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		maxn=-1;	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<s;
		return 0;
	}
	return 0;
}