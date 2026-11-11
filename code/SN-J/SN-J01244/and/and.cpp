#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
int a[212345],v[212345],F=0;
void dfs(int p){
	if(p>m){
//	for(int i=1;i<=n;i++) cout<<v[i]<<" ";
//	cout<<endl;
		int aa=2147483647;
		for(int i=1;i<=n;i++){
			if(v[i]) aa=aa&a[i];
		}
		ans=max(ans,aa);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==F){
			v[i]=1-F;
			dfs(p+1);
			v[i]=F;
		}
	}
	return;
}
void f(){
	cin>>n>>m;
	if(m>n/2) F=1,m=n-m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=F;
	}
	dfs(1);
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	f();
	return 0;
}
