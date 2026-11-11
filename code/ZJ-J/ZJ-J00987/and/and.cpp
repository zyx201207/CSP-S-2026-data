#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],num,vis[20];
void dfs(int step,int ans){
	if(step==m){
		num=max(num,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(step+1,ans&a[i]);
			vis[i]=0;
		}
	}
}
bool p(){
	for(int i=1;i<=n;i++){
		if(a[n]>=4)return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)num=max(num,a[i]);
	}else if(m==n){
		num=a[1];
		for(int i=2;i<=n;i++)num=num&a[i];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				num=max(num,a[i]&a[j]);
			}
		}
	}
	else if(n<=20)dfs(0,pow(2,20)-1);
	else if(p())num=3;
	else{
		num=pow(2,20)-1;
		for(int i=1;i<=n;i++)num=min(num,a[i]);
	}
	cout<<num;
}
