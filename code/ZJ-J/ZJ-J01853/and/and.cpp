#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[2005];
int dfs(int step,int last,int sum){
	if(step>=m){
		return sum;
	}
	int maxn=0;
	for(int i=last+1;i<=n;i++){
		maxn=max(maxn,dfs(step+1,i,sum&a[i]));
	}
	return maxn;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
	}
	else if(m==n){
		int ans=pow(2,32)-1;
		for(int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}
	else{
		cout<<dfs(0,0,pow(2,32)-1);
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}