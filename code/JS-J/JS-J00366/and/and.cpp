#include<bits/stdc++.h>
using namespace std;
int n,m,a[20000005],ans;
void dfs(long long step,int he,long long x){
	if(x==m){
		ans=max(ans,he);
		return;
	}if(step==n+1){
		return;
	}
	dfs(step+1,he&a[step],x+1);
	dfs(step+1,he,x);
}bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
	    dfs(1,(int)pow(2,15)-1,0);
	    cout<<ans;
	    return 0;
	}else if(m==1){
		int ans=0;
	   for(int i=1;i<=n;i++){
		   ans=max(ans,a[i]);
	   }cout<<ans;
	   return 0;
	}else if(m==2){
		int ans=0;
	   for(int i=1;i<n;i++){
		   for(int j=i+1;j<=n;j++){
			   ans=max(ans,a[j]&a[i]);
		   }
	   }cout<<ans;
	   return 0;
	}else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
}
