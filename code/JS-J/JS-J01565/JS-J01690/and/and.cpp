#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],maxn;
void dfs(int len,int r,int sum,int k){
	if(len==r){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=k;i<=n;i++){
		if(!len){
			dfs(len+1,r,a[i],i+1);
		}
		else{
			dfs(len+1,r,sum&a[i],i+1);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==n){
		scanf("%lld",&a[1]);
		maxn=a[1];
		for(int i=2;i<=n;i++){
			scanf("%lld",&a[i]);
			maxn&=a[i];
		}
		cout<<maxn;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,m,0,1);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
