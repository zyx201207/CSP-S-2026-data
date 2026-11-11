#include<bits/stdc++.h>
using namespace std;
int a[200007],maxa=-1;
int as[200007];
int n,m,sum;
void dfs(int vis,int now,int nowsum){
	if(vis==n){
		if(now==m){
			sum=max(sum,nowsum);
		}
		return;
	}
	dfs(vis+1,now,nowsum);
	dfs(vis+1,now+1,nowsum&a[vis+1]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	as[1]=a[1];
	for(int i=2;i<=n;i++){
		as[i]=(as[i-1]&a[i]);
	}
	if(m==1) cout<<maxa;
	
	else if(m==n){
		cout<<as[n];
	}
	
	else if(m==2){
		int ans=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));	
			}
		}
		cout<<ans;
	}
	
	else{
		dfs(0,0,2147483647);
		cout<<sum;
	}
	return 0;
}
//9 2
//1 2 3 4 5 6 7 8 9
