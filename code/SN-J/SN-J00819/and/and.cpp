#include<bits/stdc++.h>
using namespace std;
int a[200001]={0};
int n,m;
int maxx=-1;
void dfs(int d,int y,int k){
	if(d==0){
		maxx=max(maxx,k);
		return ;
	}
	for(int i=y;i<=n-d+1;i++){
		dfs(d-1,i+1,(k&a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n]; 
	}
	if(m==n){
		int k=a[1];
		for(int i=2;i<=n;i++){
			k=(k&a[i]);
		}
		cout<<k;
	}
	if(m==2){
		int k=(a[1]&a[2]);
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				k=max(k,(a[i]&a[j]));
			}
		}
		cout<<k;
	}else{
		for(int i=1;i<=n-m+1;i++){
			dfs(m-1,i+1,a[i]);
		}
		cout<<maxx;
	}
}
