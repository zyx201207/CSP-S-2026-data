#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20010],mx;
void dfs(int i,long long ans,int q){
	if(i==n+2){
		return;
	}else{
		if(q==m){
			mx=max(mx,ans);
			return;
		}else{
			dfs(i+1,ans&a[i],q+1);
			dfs(i+1,ans,q);
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,INT_MAX,0);
		cout<<mx;
	}else{
		if(m==1){
			for(int i=1;i<=n;i++){
				mx=max(mx,a[i]);
			}
			cout<<mx;
			return 0;
		}
		if(m==n){
			mx=a[1];
			for(int i=2;i<=n;i++){
				mx&=a[i];
			}
			cout<<mx;
			return 0;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					long long ans=a[i]&a[j];
					mx=max(mx,ans);
				}
			}
			cout<<mx;
			return 0;
		}
	}
	return 0;
}
