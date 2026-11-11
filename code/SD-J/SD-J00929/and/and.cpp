#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int andd(int a,int b){
	int ans=0,f=1;
	while(a!=0&&b!=0){
		if(a%2==1&&b%2==1){
			ans+=f;
		}
		f=f*2;
		a=a/2;
		b=b/2;
	}
	return ans;
}
void dfs(int k,int ansa,int sum){
	if(sum>=m){
		ans=max(ans,ansa);
		return;
	}
	if(k>n){
		return;
	}
	if(sum==0){
		dfs(k+1,0,0);
		dfs(k+1,a[k+1],1);
	}
	else{
		dfs(k+1,andd(ansa,a[k]),sum+1);
		dfs(k+1,ansa,sum);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=andd(ans,a[i]);
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(andd(a[i],a[j]),ans);
			}
		}
	}
	cout<<ans;
	return 0;
}
