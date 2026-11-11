#include<bits/stdc++.h>
using namespace std;
int n,m,a[100100],ans[100100],mx;bool vis[100100];
void dfs(int step){
	if(step==m+1){
		int aans=ans[1];
		for(int i=2;i<=m;i++){
			aans=aans & ans[i];
		}
		mx=max(mx,aans);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[step]=a[i];
			dfs(step+1);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000)return 0;
	if(n<=20){
		dfs(1);
		cout<<mx;
	}
	else{
		if(m==1){
			for(int i=1;i<=n;i++){
				mx=max(mx,a[i]);
			}
			cout<<mx;
		}
		else if(m==n){
			mx=a[1];
			for(int i=2;i<=n;i++){
				mx=mx & a[i];
			}
			cout<<mx;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					mx=max(mx,a[i] & a[j]);
				}
			}
			cout<<mx;
		}
	}
	return 0;
}

