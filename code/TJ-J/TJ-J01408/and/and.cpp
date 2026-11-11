#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=INT_MIN;
void dfs(int k,int sum,int fa){
	if(sum<=ans)return;
	if(k==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=fa-1;i>=1;i--){
		dfs(k+1,sum&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=20){
		for(int i=n;i>=1;i--){
			dfs(1,a[i],i);
		}
		cout<<ans;
	}else if(m==1){
		cout<<a[n];
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else{
		for(int i=n;i>=1;i--){
			dfs(1,a[i],i);
		}
		cout<<ans;
	}
	return 0;
}
