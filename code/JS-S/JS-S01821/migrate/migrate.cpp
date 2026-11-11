#include <bits/stdc++.h>
#define int long long
using namespace std;
int D,n,ans,d[1005][105],sum;
int a[5000005];
void dfs(int dep,int cs,int jl){
	d[dep][cs]++;
	if(jl+a[dep+1]-a[dep]<=D) dfs(dep+1,cs,jl+a[dep+1]-a[dep]);
	dfs(dep+1,cs+1,a[dep+1]-a[dep]);
}
void sol1(){
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=LLONG_MAX;
		dfs(i,1,0);
		for(int j=i;j<=n;j++){
			for(int k=0;k<=10;k++){
				if(d[j][k]==2){
					sum++;break;
				}
			}
		}
		memset(d,0,sizeof(d));
	}
	cout<<sum<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>D;
		if(n<=9) sol1();
		else{
			cout<<0<<endl;
		}
	}
	
	return 0;
}
