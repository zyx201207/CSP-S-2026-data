#include<bits/stdc++.h>
using namespace std;
int a[200010];
int ans=0;
int n,m;
int dfs(int num,int x,int i){
	if(num==0){
		ans=max(ans,x);
		return 0;
	}
	if(i==n){
		return 0;
	}
	for(int j=i+1;j<n;j++){
		if(num==m){
			x=a[j];
		}
		dfs(num-1,x&a[j],j);
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(m,0,-1);
		cout<<ans;
		return 0;
	}
	else{
		if(m==1){
			int maxx=-1;
			for(int i=0;i<n;i++){
				maxx=max(a[i],maxx);
			}
			cout<<maxx;
		}
		else if(m==n){
			int ans2=a[0];
			for(int i=0;i<n;i++){
				ans2=ans2&a[i];
			}
			cout<<ans2;
		}
		else if(m==2){
			dfs(m,0,-1);
			cout<<ans;
		}
		else if(m==n-1){
			int ans3=a[0];
			for(int i=0;i<n;i++){
				ans3=ans3&a[i];
			}
			int ans4=0;
			for(int i=0;i<n;i++){
				ans4=max(ans4,ans3&a[i]);
			}
		}
		int f=0;
		for(int i=0;i<n;i++){
			for(int j=1;j<=a[i]+1;j*=2){
				if(j-1==a[i]){
					f+=1;
				}
			}
		}
		if(f==n){
			sort(a,a+n);
			cout<<a[n-1-m];
		}
	}
	return 0;
}