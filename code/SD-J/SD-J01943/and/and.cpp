#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
int d[N];
int n,m;
int ans;
void dfs(int cnt,int sum,int stp){
	if(cnt==m){
		ans=max(ans,sum);
	}
	for(int i=stp;i<n;i++){
		if(d[i]==0){
			d[i]=1;
			if(cnt==0){
				dfs(cnt+1,a[i],i+1);
			}
			else{
			dfs(cnt+1,(sum&a[i]),i+1);
		}
			d[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0,0);
	cout<<ans;
}
