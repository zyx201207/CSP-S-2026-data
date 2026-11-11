#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200005];
void dfs(int dep,long long sum,bool flag){
	if(dep==m+1){
		ans=max(ans,sum);
		return;
	}
	if(sum==0){
		if(!flag){
			dfs(dep+1,a[dep],1);
			dfs(dep+1,0,0);
		}else{
			return;
		}
	}else{
		dfs(dep+1,a[dep]&sum,flag);
		dfs(dep+1,sum,flag);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0,0);
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}else if(m==n-1){
		int pos1=1,pos2;
		for(int i=n-1;i>=1;i--){
			if((int)log2(a[n])!=(int)log2(a[i])){
				pos1=i+1;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(i!=pos1){
				ans=a[i];
				pos2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(i!=pos1&&i!=pos2){
				ans&=a[i];
			}
		}
	}else{
		ans=a[n];
		for(int i=n-1;i>=1;i--){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
