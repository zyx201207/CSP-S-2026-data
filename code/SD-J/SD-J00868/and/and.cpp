#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
void dfs(long long t,long long j,long long anss){
	if(t>m){
		ans=max(ans,anss);
	//	cout<<anss<<' ';
		return;
	}else if(anss<ans){
		return;
	}else if((m-t)>(n-j)){
		return;
	}
	for(long long i=j+1;i<=n;i++){
		if(t==1)anss=a[i];
	//	cout<<anss<<'*'<<' '<<i<<endl;
		dfs(t+1,i,(anss&a[i]));
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
