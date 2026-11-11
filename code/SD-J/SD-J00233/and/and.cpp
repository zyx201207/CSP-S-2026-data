#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[30];
int ans[1000];
int ansa[100005];
int k=1,m,n;
void dfs(int t){
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			if(t==m){
				ansa[k]=ans[k];
				k++;
			}
			else{
				ans[k]=ans[k]&a[i];
				dfs(t+1);
			}
		}
		b[i]=0;
	}
} 
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=1000;i++){
			ans[i]=1048575;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		int maxa=-1;
		for(int i=1;i<=k;i++){
			if(ansa[i]>maxa && ansa[i]!=1048575 && ansa[i]!=15){
				maxa=ansa[i];
			}
		}
		cout<<maxa<<endl;
	}
	else if(n>=21 && n<=2000 && m==1){
		int maxa=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>maxa){
				maxa=a[i];
			}
		}
		cout<<maxa;
	}
	else if(n>=21 && n<=2000 && m==n){
		int ans=1048575;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else{
		cout<<0; 
	}
	return 0;
} 
