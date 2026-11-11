#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000001];
long long ans,cnt;
void dfs(int i,int j,int x,int y){
	if(i==j&&x==y){
		++cnt;
		return;
	}
	for(int k=i+1;k<=j;++k){
		if(abs(a[i]-a[k])<=d){
			dfs(k,j,x+1,y);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<i;++j){
				if(i-j>=3){
					for(int k=3;k<=i-j;++k){
						cnt=0;
					    dfs(j,i,1,k);
					    if(cnt==2){
					    	++ans;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
